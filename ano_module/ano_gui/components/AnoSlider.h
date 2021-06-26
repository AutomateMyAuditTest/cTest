/** AnoSlider.h */

#pragma once

namespace ano
{
//==============================================================================
/*
*/
class AnoSlider : public juce::Component
{
public:
    AnoSlider();
    AnoSlider(const juce::String sliderName, bool showLabel);
    ~AnoSlider() override;

    void paint(juce::Graphics&) override;
    void resized() override;
    void setSliderName(const juce::String sliderName);
    juce::Slider& getSliderRef();
    juce::Slider* getSliderPtr();

private:
    juce::Rectangle<int> bounds;
    juce::Label label;
    juce::Slider slider;

    bool hasLabel {false};

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AnoSlider)
};

} // namespace ano
