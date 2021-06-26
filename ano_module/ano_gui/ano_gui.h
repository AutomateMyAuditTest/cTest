/**
 * ano_gui.h
 * Copyright (c) 2020 Anoesis Audio
 */

#pragma once

#if 0

    BEGIN_JUCE_MODULE_DECLARATION

        ID:                 ano_gui
        vendor:             AnoesisAudio
        version:            0.0.1
        name:               AnoesisAudio GUI classes
        description:        GUI classes for AnoesisAudio apps.
        website:            http://www.anoesisaudio.com
        license:            Commercial

        dependencies:       juce_gui_basics

    END_JUCE_MODULE_DECLARATION

#endif

#define ANO_GUI_H_INCLUDED

#include <juce_core/juce_core.h>
#include <juce_gui_basics/juce_gui_basics.h>

#include "components/AnoSlider.h"
#include "lookAndFeels/ano_laf_1.h"
#include "other/ano_graphics_header.h"
#include "views/VWpSimpleResonator.h"
#include "views/VWpSmithAngellResonator.h"
