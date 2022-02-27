/** 
 * VWpSmithAngellResonator.h
 * Copyright (c) 2020 Anoesis Audio
 */

#pragma once

#include <ano_processor/ano_processor.h>
#include <ano_gui/ano_gui.h>

namespace ano
{
//==============================================================================
/*   d   e   s   c   r   i   p   t   i   o   n
*/
class VWpSmithAngellResonator : public juce::Component
{
public:
    VWpSmithAngellResonator();
    VWpSmithAngellResonator(juce::AudioProcessor& p);
    ~VWpSmithAngellResonator() override;

    void paint(juce::Graphics&) override;
    void resized() override;

    juce::Slider* getSldPtrFc();
    juce::Slider* getSldPtrQ();

private:
    juce::AudioProcessor& proc;
    juce::Rectangle<int> bounds;

    juce::Label lblHeader;
    ano::AnoSlider sldFc, sldQ;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(VWpSmithAngellResonator)
};

} // namespace ano
