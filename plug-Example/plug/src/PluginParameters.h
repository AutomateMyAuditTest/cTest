/** PluginParameters.h
    Copyright (c) 2021 AnoesisAudio
*/

#pragma once
#include <juce_audio_processors/juce_audio_processors.h>
#include <atomic>

// namespace to hold constant string ids
namespace ParameterName
{
constexpr auto prmGainId = "gain";
} // namespace ParameterName

struct PluginParameters
{
    // parameter values from processor
    juce::AudioParameterFloat* prmGain = nullptr;

    explicit PluginParameters(juce::AudioProcessorValueTreeState& state);

    static juce::AudioProcessorValueTreeState::ParameterLayout makeLayout();
};
