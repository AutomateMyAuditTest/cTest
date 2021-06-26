/** 
 * VWpSimpleResonator.h
 * Copyright (c) 2020 Anoesis Audio
 */

#pragma once

#include <ano_processor/ano_processor.h>

namespace ano
{
//==============================================================================
/*   d   e   s   c   r   i   p   t   i   o   n
*/
class VWpSimpleResonator : public juce::Component
{
public:
    VWpSimpleResonator();
    VWpSimpleResonator(juce::AudioProcessor& p);
    ~VWpSimpleResonator() override;

    void paint(juce::Graphics&) override;
    void resized() override;

    juce::Slider* getSldPtrFc();
    juce::Slider* getSldPtrQ();

private:
    juce::AudioProcessor& proc;
    juce::Rectangle<int> bounds;

    juce::Label lblHeader;
    ano::AnoSlider sldFc, sldQ;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(VWpSimpleResonator)
};

} // namespace ano
