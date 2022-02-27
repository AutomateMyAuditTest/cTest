/**
 * VWpSimpleResonator.cpp
 * Copyright (c) 2020 Anoesis Audio
 */

#include "VWpSimpleResonator.h"

ano::VWpSimpleResonator::VWpSimpleResonator(juce::AudioProcessor& p)
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

ano::VWpSimpleResonator::~VWpSimpleResonator()
{
}

void ano::VWpSimpleResonator::paint(juce::Graphics& g)
{
    //  https://docs.juce.com/master/namespaceColour.html#af4313cd5186251a3a854a0e04462ed42
    g.fillAll(juce::Colours::aqua);

    // start gui dev grid -----------------------------------------
    float rows = 16.0;
    float cols = 22.0;

    for (int i = 0; i < (int)rows; ++i) // rows
    {
        g.setColour(juce::Colours::silver.withAlpha(0.3f));
        auto x = (float)bounds.getY() + (float)bounds.getHeight() * (float)i * (1.0f / rows);
        if (i > 0)
        {
            auto xx = juce::roundToInt(x);
            g.drawHorizontalLine(xx, (float)bounds.getX(), (float)bounds.getRight());
        }  
    }

    for (int i = 0; i < (int)cols; ++i) // columns
    {
        g.setColour(juce::Colours::silver.withAlpha(0.3f));
        auto x = (float)bounds.getX() + (float)bounds.getWidth() * (float)i * (1.0f / cols);
        if (i > 0)
        {
            auto xx = juce::roundToInt(x);
            g.drawHorizontalLine(xx, (float)bounds.getX(), (float)bounds.getRight());
        }  
    }
    // end gui dev grid -------------------------------------------
}

void ano::VWpSimpleResonator::resized()
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
juce::Slider* ano::VWpSimpleResonator::getSldPtrFc()
{
    return sldFc.getSliderPtr();
}

juce::Slider* ano::VWpSimpleResonator::getSldPtrQ()
{
    return sldQ.getSliderPtr();
}
