/**
 * VWpSmithAngellResonator.cpp
 * Copyright (c) 2020 Anoesis Audio
 */

#include "VWpSmithAngellResonator.h"

ano::VWpSmithAngellResonator::VWpSmithAngellResonator(juce::AudioProcessor& p)
    : proc(p)
    , lblHeader("lblHeader", "Simple Resonator")
    , sldFc("Fc", true)
    , sldQ("Q", true)
{
    /** add components */
    addAndMakeVisible(lblHeader);
    addAndMakeVisible(sldFc);
    addAndMakeVisible(sldQ);
    setSize(700, 350);
}

ano::VWpSmithAngellResonator::~VWpSmithAngellResonator()
{
}

void ano::VWpSmithAngellResonator::paint(juce::Graphics& g)
{
    // https://docs.juce.com/master/namespaceColours.html#af4313cd5186251a3a854a0e04462ed42
    g.fillAll(juce::Colours::greenyellow);

    // start gui dev grid -----------------------------------------
    float rows = 16.0;
    float cols = 22.0;

    for (int i = 0; i < rows; ++i) // rows
    {
        g.setColour(juce::Colours::silver.withAlpha(0.3f));
        auto x = bounds.getY() + bounds.getHeight() * i * (1.0f / rows);
        if (i > 0)
            g.drawHorizontalLine(
                juce::roundToInt(x), bounds.getX(), bounds.getRight());
    }

    for (int i = 0; i < cols; ++i) // columns
    {
        g.setColour(juce::Colours::silver.withAlpha(0.3f));
        auto x = bounds.getX() + bounds.getWidth() * i * (1.0f / cols);
        if (i > 0)
            g.drawVerticalLine(
                juce::roundToInt(x), bounds.getY(), bounds.getBottom());
    }
    // end gui dev grid -------------------------------------------
}

void ano::VWpSmithAngellResonator::resized()
{
    bounds = getLocalBounds();

    // juce grid 16 rows by 22 columns
    juce::Grid grid;
    using Track = juce::Grid::TrackInfo;

    grid.templateRows = {Track(1_fr),
                         Track(1_fr),
                         Track(1_fr),
                         Track(1_fr),
                         Track(1_fr),
                         Track(1_fr),
                         Track(1_fr),
                         Track(1_fr),
                         Track(1_fr),
                         Track(1_fr),
                         Track(1_fr),
                         Track(1_fr),
                         Track(1_fr),
                         Track(1_fr),
                         Track(1_fr),
                         Track(1_fr)};

    grid.templateColumns = {
        Track(1_fr), Track(1_fr), Track(1_fr), Track(1_fr), Track(1_fr), Track(1_fr),
        Track(1_fr), Track(1_fr), Track(1_fr), Track(1_fr), Track(1_fr), Track(1_fr),
        Track(1_fr), Track(1_fr), Track(1_fr), Track(1_fr), Track(1_fr), Track(1_fr),
        Track(1_fr), Track(1_fr), Track(1_fr), Track(1_fr)};

    // withArea  rowStart, columnStart, rowEnd, columnEnd)
    grid.items = {juce::GridItem(lblHeader).withArea(1, 1, 3, 23),
                  juce::GridItem(sldFc).withArea(6, 4, 11, 9),
                  juce::GridItem(sldQ).withArea(11, 4, 16, 9)};

    grid.performLayout(bounds);
}

/** component getters */
juce::Slider* ano::VWpSmithAngellResonator::getSldPtrFc()
{
    return sldFc.getSliderPtr();
}

juce::Slider* ano::VWpSmithAngellResonator::getSldPtrQ()
{
    return sldQ.getSliderPtr();
}
