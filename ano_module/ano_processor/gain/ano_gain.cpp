/** 
 * ano_gain.cpp
 * Copyright (c) 2020 AnoesisAudio
 */

#include "ano_gain.h"

//==============================================================================
template <typename SampleType, size_t maxNumChannels>
ano::Gain::Processor<SampleType, maxNumChannels>::Processor()
    : state(new Parameters<NumericType>)
{
    reset();
}

template <typename SampleType, size_t maxNumChannels>
void ano::Gain::Processor<SampleType, maxNumChannels>::prepare(
    const juce::dsp::ProcessSpec& spec)
{
    jassert(spec.sampleRate > 0);
    jassert(spec.numChannels <= maxNumChannels);

    sampleRate = (float) spec.sampleRate;

    reset();
}

template <typename SampleType, size_t maxNumChannels>
void ano::Gain::Processor<SampleType, maxNumChannels>::reset() noexcept
{
    if (sampleRate > 0)
        gain.reset(sampleRate, rampDurationSeconds);
}

template <typename SampleType, size_t maxNumChannels>
void ano::Gain::Processor<SampleType, maxNumChannels>::setGainLinear(
    SampleType newGain) noexcept
{
    gain.setTargetValue(newGain);
}

template <typename SampleType, size_t maxNumChannels>
void ano::Gain::Processor<SampleType, maxNumChannels>::setGainDecibels(
    SampleType newGainDecibels) noexcept
{
    setGainLinear(juce::Decibels::decibelsToGain<SampleType>(newGainDecibels));
}

template <typename SampleType, size_t maxNumChannels>
SampleType
    ano::Gain::Processor<SampleType, maxNumChannels>::getGainLinear() const noexcept
{
    return gain.getTargetValue();
}

template <typename SampleType, size_t maxNumChannels>
SampleType ano::Gain::Processor<SampleType, maxNumChannels>::getGainDecibels()
    const noexcept
{
    return juce::Decibels::gainToDecibels<SampleType>(getGainLinear());
}

template <typename SampleType, size_t maxNumChannels>
void ano::Gain::Processor<SampleType, maxNumChannels>::setRampDurationSeconds(
    double newDurationSeconds) noexcept
{
    if (rampDurationSeconds != newDurationSeconds)
    {
        rampDurationSeconds = (float) newDurationSeconds;
        reset();
    }
}

template <typename SampleType, size_t maxNumChannels>
double ano::Gain::Processor<SampleType, maxNumChannels>::getRampDurationSeconds()
    const noexcept
{
    return rampDurationSeconds;
}

template <typename SampleType, size_t maxNumChannels>
bool ano::Gain::Processor<SampleType, maxNumChannels>::isSmoothing() const noexcept
{
    return gain.isSmoothing();
}

//==============================================================================
template class ano::Gain::Processor<float, 2>;
template class ano::Gain::Processor<double, 2>;
