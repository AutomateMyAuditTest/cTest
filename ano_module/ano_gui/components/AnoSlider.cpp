/** AnoSlider.cpp */

#include "AnoSlider.h"

ano::AnoSlider::AnoSlider()
    : label("hdj", "sliderName")
    , slider("name")
{
    addAndMakeVisible(label);
    label.setFont(juce::Font(24.0f, juce::Font::plain));
    label.setJustificationType(juce::Justification::centredLeft);
    label.setEditable(false, false, false);
    label.setColour(juce::Label::ColourIds::textColourId, juce::Colour(0xff483d8b));
    label.setColour(juce::Label::outlineColourId, juce::Colour(0x00000000));
    label.setColour(juce::Label::backgroundColourId, juce::Colour(0x00000000));
    label.setJustificationType(36);

    addAndMakeVisible(slider);
    slider.setSkewFactorFromMidPoint(1.0);
    slider.setTooltip("sliderName");
    slider.setTextBoxStyle(
        juce::Slider::TextEntryBoxPosition::TextBoxBelow, true, 130, 30);
    slider.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);

    setSize(200, 200);
}

//==============================================================================
ano::AnoSlider::AnoSlider(const juce::String sliderName, bool showLabel)
    : label("hdj", sliderName)
    , slider(sliderName)
{
    hasLabel = showLabel;

    if (hasLabel == true)
    {
        addAndMakeVisible(label);
        label.setFont(juce::Font(24.0f, juce::Font::plain));
        label.setJustificationType(juce::Justification::centredLeft);
        label.setEditable(false, false, false);
        label.setColour(juce::Label::ColourIds::textColourId,
                        juce::Colour(0xff483d8b));
        label.setColour(juce::Label::outlineColourId, juce::Colour(0x12e9dede));
        label.setColour(juce::Label::backgroundColourId, juce::Colour(0xffffff));
        label.setJustificationType(36);
    }

    addAndMakeVisible(slider);
    slider.setSkewFactorFromMidPoint(1.0);
    slider.setTooltip(sliderName);
    slider.setTextBoxStyle(
        juce::Slider::TextEntryBoxPosition::TextBoxBelow, true, 130, 50);
    slider.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);

    setSize(200, 200);
}

ano::AnoSlider::~AnoSlider()
{
}

//==============================================================================
void ano::AnoSlider::setSliderName(const juce::String sliderName)
{
    label.setText(sliderName, juce::dontSendNotification);
    slider.setName(sliderName);
    slider.setTooltip(sliderName);
}

void ano::AnoSlider::paint(juce::Graphics& g)
{
    juce::ignoreUnused(g);
}

void ano::AnoSlider::resized()
{
    bounds = getLocalBounds();

    // juce grid 1 columns by 4 rows
    juce::Grid grid;
    using Track = juce::Grid::TrackInfo;

    grid.templateRows = {Track(1_fr), Track(1_fr), Track(1_fr), Track(1_fr)};
    grid.templateColumns = {Track(1_fr)};

    // withArea  rowStart, columnStart, rowEnd, columnEnd)
    if (hasLabel == true)
    {
        grid.items = {juce::GridItem(label).withArea(1, 1, 2, 2),
                      juce::GridItem(slider).withArea(2, 1, 5, 2)};
    }
    else
    {
        grid.items = {juce::GridItem(slider).withArea(2, 1, 5, 2)};
    }

    int w = int(slider.getWidth() * 0.65);
    int h = int(slider.getHeight() * 0.15);
    slider.setTextBoxStyle(
        juce::Slider::TextEntryBoxPosition::TextBoxBelow, true, w, h);

    grid.performLayout(bounds);
}

juce::Slider& ano::AnoSlider::getSliderRef()
{
    return slider;
}

juce::Slider* ano::AnoSlider::getSliderPtr()
{
    return &slider;
}
