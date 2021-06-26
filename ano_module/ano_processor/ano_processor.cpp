/**
 * ano_gui.cpp
 * Copyright (c) 2020 Anoesis Audio
 */

#ifdef ANO_PROCESSORS_H_INCLUDED
/** Throw if this file has already been included elsewhere. */
#error "Incorrect use of JUCE cpp file"
#endif

#include "ano_processor.h"

#include "filters/PWpSimpleResonator.cpp"
#include "filters/PWpSmithAngellResonator.cpp"
#include "gain/ano_gain.cpp"
#include "parameters/ano_parameter_header.cpp"
