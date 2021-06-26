/** 
 * ano_gain.h
 * Mostly copied from juce_Gain.
*/

#pragma once

namespace ano
{
namespace Gain
{
template <typename NumericType>
struct Parameters : public juce::dsp::ProcessorState
{
    //==============================================================================
    /** This structure is ref-counted, so this is a handy type that can be used as a pointer to one. */
    using Ptr = juce::ReferenceCountedObjectPtr<Parameters>;

    //==============================================================================
    Parameters() = default;

    Parameters(const Parameters& o)
        : gain(o.gain)
    {
    }

    Parameters& operator=(const Parameters& o) noexcept
    {
        gain = o.gain;
        return *this;
    }

    //==============================================================================
    NumericType gain = 0; // Should be in decibels, -60 to 0
};

/** A gain for a specified number of channels. */
template <typename SampleType, size_t maxNumChannels = 2>
class Processor
{
public:
    /** The NumericType is the underlying primitive type used by the 
 *  SampleType (which could be either a primitive or vector)
*/
    using NumericType =
        typename juce::dsp::SampleTypeHelpers::ElementType<SampleType>::Type;

    /** Creates a filter with default parameters. */
    Processor();

    Processor(const Processor&) = default; /** Creates a copy of another filter. */
    Processor(Processor&&) = default; /** Move constructor */

    //==============================================================================
    /** Initializes the processor. */
    void prepare(const juce::dsp::ProcessSpec& spec);

    /** Resets the internal state variables of the processor. */
    void reset() noexcept;

    //==============================================================================
    /** Applies a new gain as a linear value. */
    void setGainLinear(SampleType newGain) noexcept;

    /** Applies a new gain as a decibel value. */
    void setGainDecibels(SampleType newGainDecibels) noexcept;

    /** Returns the current gain as a linear value. */
    SampleType getGainLinear() const noexcept;

    /** Returns the current gain in decibels. */
    SampleType getGainDecibels() const noexcept;

    /** Sets the length of the ramp used for smoothing gain changes. */
    void setRampDurationSeconds(double newDurationSeconds) noexcept;

    /** Returns the ramp duration in seconds. */
    double getRampDurationSeconds() const noexcept;

    /** Returns true if the current value is currently being interpolated. */
    bool isSmoothing() const noexcept;

    //==============================================================================
    /** The parameters of the gain. */
    typename Parameters<NumericType>::Ptr state;

    /**  */
    template <typename ProcessContext>
    void process(const ProcessContext& context) noexcept
    {
        auto& inputBlock = context.getInputBlock();
        auto& outputBlock = context.getOutputBlock();

        auto numSamples = inputBlock.getNumSamples();
        auto numChannels = inputBlock.getNumChannels();

        jassert(inputBlock.getNumChannels() == numChannels);
        jassert(inputBlock.getNumSamples() == numSamples);

        // skip if bypass is true
        if (context.isBypassed)
        {
            gain.skip(static_cast<int>(numSamples));

            if (context.usesSeparateInputAndOutputBlocks())
                outputBlock.copyFrom(inputBlock);

            return;
        }

        // get current state
        setGainDecibels(state->gain);

        // process samples
        if (numChannels == 1)
        {
            auto* src = inputBlock.getChannelPointer(0);
            auto* dst = outputBlock.getChannelPointer(0);

            for (size_t i = 0; i < numSamples; ++i)
                dst[i] = src[i] * gain.getNextValue();
        }
        else
        {
            JUCE_BEGIN_IGNORE_WARNINGS_MSVC(6255 6386)
            auto* gains =
                static_cast<SampleType*>(alloca(sizeof(SampleType) * numSamples));

            for (size_t i = 0; i < numSamples; ++i)
                gains[i] = gain.getNextValue();
            JUCE_END_IGNORE_WARNINGS_MSVC

            for (size_t chan = 0; chan < numChannels; ++chan)
                juce::FloatVectorOperations::multiply(
                    outputBlock.getChannelPointer(chan),
                    inputBlock.getChannelPointer(chan),
                    gains,
                    static_cast<int>(numSamples));
        }
    }

private:
    SampleType sampleRate {SampleType(0)};

    juce::SmoothedValue<SampleType> gain;
    SampleType rampDurationSeconds;

    JUCE_LEAK_DETECTOR(Processor)
};

} // namespace Gain
} // namespace ano
