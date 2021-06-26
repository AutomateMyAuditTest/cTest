/**
 * ano_processor.h
 * Copyright (c) 2020 Anoesis Audio
 */

#pragma once

#if 0

    BEGIN_JUCE_MODULE_DECLARATION

        ID:                 ano_processor
        vendor:             AnoesisAudio
        version:            0.0.1
        name:               AnoesisAudio processor classes
        description:        Audio processor classes for AnoesisAudio apps.
        website:            http://www.anoesisaudio.com
        license:            Commercial

        dependencies:       juce_audio_processors, juce_dsp
        OSXFrameworks:      Accelerate
        iOSFrameworks:      Accelerate

    END_JUCE_MODULE_DECLARATION

#endif

#define ANO_PROCESSORS_H_INCLUDED

#include <juce_core/juce_core.h>
#include <juce_audio_processors/juce_audio_processors.h>
#include <juce_dsp/juce_dsp.h>

#include "filters/PWpSimpleResonator.h"
#include "filters/PWpSmithAngellResonator.h"
#include "gain/ano_gain.h"
#include "parameters/ano_parameter_header.h"
