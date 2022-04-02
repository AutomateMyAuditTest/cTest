/** PluginParameters.cpp
    Copyright (c) 2021 AnoesisAudio
*/

#include "PluginParameters.h"

PluginParameters::PluginParameters(juce::AudioProcessorValueTreeState& state)
{
    prmGain = dynamic_cast<juce::AudioParameterFloat*>(
        state.getParameter(ParameterName::prmGainId));
}

juce::AudioProcessorValueTreeState::ParameterLayout PluginParameters::makeLayout()
{
    return {std::make_unique<juce::AudioParameterFloat>(
        juce::ParameterID {ParameterName::prmGainId, 1},
        TRANS("Gain"),
        juce::NormalisableRange<float>(-60.0f, 0.0f, 0.0001f),
        -10.f,
        TRANS("Gain"),
        juce::AudioProcessorParameter::genericParameter,
        [](float value, int) { return juce::String(value, 1); },
        [](const juce::String& text) { return text.getFloatValue(); })};
}
