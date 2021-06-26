/** 
 * PWpSmithAngellResonator.cpp
 * Copyright (c) 2020 AnoesisAudio
 */

#include "PWpSmithAngellResonator.h"

//==============================================================================
template <typename SampleType, size_t maxNumChannels>
ano::PWpSmithAngellResonator::Processor<SampleType, maxNumChannels>::Processor()
    : state(new Parameters<NumericType>)
{
    reset();
}

template <typename SampleType, size_t maxNumChannels>
void ano::PWpSmithAngellResonator::Processor<SampleType, maxNumChannels>::prepare(
    const juce::dsp::ProcessSpec& spec)
{
    jassert(spec.sampleRate > 0);
    jassert(spec.numChannels <= maxNumChannels);

    sampleRate = (SampleType) spec.sampleRate;

    reset();
}

template <typename SampleType, size_t maxNumChannels>
void ano::PWpSmithAngellResonator::Processor<SampleType,
                                             maxNumChannels>::reset() noexcept
{
    for (int i = 0; i < 2; i++)
    {
        x1[i] = 0.0;
        x2[i] = 0.0;
        y1[i] = 0.0;
        y2[i] = 0.0;
    }

    a1 = 0.0;
}

//==============================================================================
template class ano::PWpSmithAngellResonator::Processor<float, 2>;
template class ano::PWpSmithAngellResonator::Processor<double, 2>;
