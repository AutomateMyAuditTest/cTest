/**
 * ano_laf_1.h
 * Copyright (c) 2020 Anoesis Audio
 */

#pragma once

namespace ano
{
class Laf1 : public juce::LookAndFeel_V4
{
    //==============================================================================
    void drawToggleButton(juce::Graphics& g,
                          juce::ToggleButton& button,
                          bool isMouseOverButton,
                          bool isButtonDown) override
    {
        auto fontSize = juce::jmin(48.0f, (float) button.getHeight() * 0.75f);
        auto tickWidth = fontSize * 1.1f;

        drawTickBox(g,
                    button,
                    4.0f,
                    ((float) button.getHeight() - tickWidth) * 0.5f,
                    tickWidth,
                    tickWidth,
                    button.getToggleState(),
                    button.isEnabled(),
                    isMouseOverButton,
                    isButtonDown);

        g.setColour(button.findColour(juce::ToggleButton::textColourId));
        g.setFont(fontSize);

        if (!button.isEnabled())
            g.setOpacity(0.5f);

        g.drawFittedText(button.getButtonText(),
                         button.getLocalBounds()
                             .withTrimmedLeft(juce::roundToInt(tickWidth) + 10)
                             .withTrimmedRight(2),
                         juce::Justification::centredLeft,
                         10);
    }

    //==============================================================================
    void drawComboBox(juce::Graphics& g,
                      int width,
                      int height,
                      bool isButtonDown,
                      int buttonX,
                      int buttonY,
                      int buttonW,
                      int buttonH,
                      juce::ComboBox& box) override
    {
        juce::ignoreUnused(isButtonDown);
        juce::ignoreUnused(buttonX);
        juce::ignoreUnused(buttonY);
        juce::ignoreUnused(buttonW);
        juce::ignoreUnused(buttonH);

        auto cornerSize =
            box.findParentComponentOfClass<juce::ChoicePropertyComponent>()
                    != nullptr
                ? 0.0f
                : 3.0f;
        juce::Rectangle<int> boxBounds(0, 0, width, height);

        g.setColour(box.findColour(juce::ComboBox::backgroundColourId));
        g.fillRoundedRectangle(boxBounds.toFloat(), cornerSize);

        g.setColour(box.findColour(juce::ComboBox::outlineColourId));
        g.drawRoundedRectangle(
            boxBounds.toFloat().reduced(0.5f, 0.5f), cornerSize, 1.0f);

        juce::Rectangle<int> arrowZone(width - 30, 0, 20, height);
        juce::Path path;
        path.startNewSubPath((float) arrowZone.getX() + 3.0f,
                             (float) arrowZone.getCentreY() - 2.0f);
        path.lineTo(static_cast<float>(arrowZone.getCentreX()),
                    (float) arrowZone.getCentreY() + 3.0f);
        path.lineTo((float) arrowZone.getRight() - 3.0f,
                    (float) arrowZone.getCentreY() - 2.0f);

        g.setColour(box.findColour(juce::ComboBox::arrowColourId)
                        .withAlpha((box.isEnabled() ? 0.9f : 0.2f)));
        g.strokePath(path, juce::PathStrokeType(2.0f));
    }

    juce::Font getComboBoxFont(juce::ComboBox& box) override
    {
        return {juce::jmin(48.0f, (float) box.getHeight() * 0.85f)};
    }

    void positionComboBoxText(juce::ComboBox& box, juce::Label& label) override
    {
        label.setBounds(1, 1, box.getWidth() - 30, box.getHeight() - 2);

        label.setFont(getComboBoxFont(box));
    }

    //==============================================================================
    void drawRotarySlider(juce::Graphics& g,
                          int x,
                          int y,
                          int width,
                          int height,
                          float sliderPos,
                          float rotaryStartAngle,
                          float rotaryEndAngle,
                          juce::Slider& slider) override
    {
        const float size = 6.0f;
        const float diameter = (float) juce::jmin(width, height) - 4.0f;
        const float radius =
            (diameter / 2.0f) * std::cos(juce::MathConstants<float>::pi / size);
        const float centreX = (float) x + (float) width * 0.5f;
        const float centreY = (float) y + (float) height * 0.5f;
        const float rx = centreX - radius;
        const float ry = centreY - radius;
        const float rw = radius * 2.0f;
        const float angle =
            rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
        const bool isMouseOver =
            slider.isMouseOverOrDragging() && slider.isEnabled();
        const float box2Size = rw * 0.8125f;
        const float box2Diff = (rw - box2Size) * 0.5f;
        const float box3Size = rw * 0.75f;
        const float box3Diff = (rw - box3Size) * 0.5f;

        if (slider.isEnabled())
            g.setColour(slider.findColour(juce::Slider::rotarySliderFillColourId)
                            .withAlpha(isMouseOver ? 1.0f : 0.7f));
        else
            g.setColour(juce::Colour(0x80808080));
        {
            juce::Path box1;
            box1.addEllipse(rx, ry, rw, rw);
            g.setColour(juce::Colour(0xFF030300));
            g.fillPath(box1);
            box1.closeSubPath();

            juce::Path box2;
            box2.addEllipse(rx + box2Diff, ry + box2Diff, box2Size, box2Size);
            g.setGradientFill(
                juce::ColourGradient(juce::Colour(0x04F0F0F0),
                                     rx + box2Diff,
                                     ry + box2Diff,
                                     juce::Colour(0x40F0F4F0).darker(0.1f),
                                     box2Size,
                                     box2Size,
                                     false));
            g.fillPath(box2);
            box2.closeSubPath();

            juce::Path needleBox;
            needleBox.addRectangle(rx, ry, rw, rw);
            g.setColour(juce::Colour(0x00F0F0F0));
            juce::AffineTransform t(
                juce::AffineTransform::rotation(angle, centreX, centreY));
            float x1 = 0.0f, y1 = 0.0f, x2 = 0.0f, y2 = rw;
            t.transformPoints(x1, y1, x2, y2);
            g.fillPath(needleBox, t);
            needleBox.closeSubPath();

            juce::Path needle;
            juce::Rectangle<float> needlePoint((rw * 0.2f) - box3Diff, radius);
            needle.addRectangle(needlePoint.withPosition(
                juce::Point<float>(centreX - (needlePoint.getWidth() / 2.0f), ry)));
            g.setColour(juce::Colour(0xFFFFFFFF));
            g.fillPath(needle,
                       juce::AffineTransform::rotation(angle, centreX, centreY));
            needle.closeSubPath();
        }
    }

    // void drawPointer (Graphics& g, const float x, const float y, const float diameter,
    //                               const Colour& colour, const int direction) noexcept
    // {}

    // juce::Label* createSliderTextBox(juce::Slider& slider) override
    // {
    // }

    //==============================================================================
};

} // namespace ano
