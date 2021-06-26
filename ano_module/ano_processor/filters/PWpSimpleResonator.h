/** 
 * PWpSimpleResonator.h
 * Copyright (c) 2020 AnoesisAudio
*/

#pragma once

namespace ano
{
namespace PWpSimpleResonator
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
        : cutt(o.cutt)
        , reso(o.reso)
    {
    }

    Parameters& operator=(const Parameters& o) noexcept
    {
        cutt = o.cutt; // filter cutoff
        reso = o.reso; // filter resonance
        return *this;
    }

    //==============================================================================
    NumericType cutt = 0;
    NumericType reso = 0;
};

/** A delay for a specified number of channels. */
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
    /** The parameters of the delay. */
    typename Parameters<NumericType>::Ptr state;

    /**  */
    template <typename ProcessContext>
    void process(const ProcessContext& context) noexcept
    {
        auto& inputBlock = context.getInputBlock();
        auto& outputBlock = context.getOutputBlock();
        auto numSamples = outputBlock.getNumSamples();
        auto numChannels = outputBlock.getNumChannels();

        jassert(inputBlock.getNumChannels() == numChannels);
        jassert(inputBlock.getNumSamples() == numSamples);

        this->freq = state->cutt * 0.5;
        this->Q = state->reso;

        // calculate coefficients
        // filterAlgorithm::kResonA in fxobjects.cpp
        auto theta_c = 2.0 * juce::MathConstants<double>::pi * freq / sampleRate;
        auto BW = freq / Q;
        auto b2 =
            std::exp(-2.0 * juce::MathConstants<double>::pi * (BW / sampleRate));
        auto b1 = ((-4 * b2) / (1 + b2)) * std::cos(theta_c);
        auto a0 = (1 - b2) * std::sqrt(1 - (std::pow(b1, 2) / (4.0 * b2)));

        // process samples
        for (juce::uint16 channel = 0; channel < numChannels; channel++)
        {
            for (juce::uint16 n = 0; n < numSamples; n++)
            {
                double x = (double) inputBlock.getSample(channel, n);
                double y = 0.0;

                y = a0 * x + a1 * x1[channel] + a2 * x2[channel] - b1 * y1[channel]
                    - b2 * y2[channel];

                x2[channel] = x1[channel];
                x1[channel] = x;
                y2[channel] = y1[channel];
                y1[channel] = y;

                outputBlock.setSample(channel, n, (float) y);
            }
        }
    }

private:
    SampleType sampleRate {SampleType(0)};

    // Variables for User to Modify Filter
    double freq = 20.0; // cutoff frequency in Hz
    double Q = 0.707; // Q => [0.1 - 10]

    // Variables for Biquad DFI Implementation
    // 2 channels - L,R : Up to 2nd Order
    double x1[2] = {0.0}; // 1 sample of delay feedforward
    double x2[2] = {0.0}; // 2 samples of delay feedforward
    double y1[2] = {0.0}; // 1 sample of delay feedback
    double y2[2] = {0.0}; // 2 samples of delay feedback

    // Filter coefficients
    double a1 = 0.0;
    double a2 = 0.0;

    JUCE_LEAK_DETECTOR(Processor)
};

} // namespace PWpSimpleResonator
} // namespace ano
