###############################################################################
#############################   Plugin settings   #############################
###############################################################################

set (BaseTargetName plug-Example)
set (CompanyName AnoesisAudio)
set (Website website)
set (ManuCode Anoe)
set (PluginCode Ace1)
set (Description "Example project for anoTemplate")

set(CMAKE_CXX_STANDARD 17)

if(APPLE)
    message(STATUS "Found APPLE")
    set (Formats AU VST VST3 Standalone)
    set (ToCopyPlugs TRUE)
endif()

if(UNIX AND NOT APPLE)
    message(STATUS "Found UNIX")
    set (Formats VST3 Standalone)
    set (ToCopyPlugs FALSE)
endif()

if(WIN32)
    message(STATUS "Found WIN32")
    set (Formats VST VST3 Standalone)
    set (ToCopyPlugs FALSE)
endif()

project(${BaseTargetName} VERSION 0.0.1)

###############################################################################
##################################   Plugins   ################################
###############################################################################

juce_add_plugin("${BaseTargetName}"
    # see https://github.com/juce-framework/JUCE/blob/master/docs/CMake%20API.md
    # VERSION 
    ICON_BIG "${CMAKE_CURRENT_SOURCE_DIR}/img/icon.png"
    ICON_SMALL "${CMAKE_CURRENT_SOURCE_DIR}/img/icon.png"
    COMPANY_NAME COMPANY_NAME ${CompanyName}
    COMPANY_WEBSITE "${CompanyName}.com"
    COMPANY_EMAIL "support@${CompanyName}.com"
    BUNDLE_ID com.${CompanyName}.${BaseTargetName}
    IS_SYNTH FALSE
    NEEDS_MIDI_INPUT FALSE
    NEEDS_MIDI_OUTPUT FALSE
    IS_MIDI_EFFECT FALSE
    EDITOR_WANTS_KEYBOARD_FOCUS FALSE
    COPY_PLUGIN_AFTER_BUILD "${ToCopyPlugs}"
    PLUGIN_MANUFACTURER_CODE "${ManuCode}"
    PLUGIN_CODE "${PluginCode}"
    FORMATS "${Formats}"
    PRODUCT_NAME "${BaseTargetName}"
    DESCRIPTION "${Description}"
    VST2_CATEGORY "kPlugCategUnknown"
    AU_MAIN_TYPE_CODE "kAudioUnitType_Effect"
)

set(SourceFiles
    # headers
    src/PluginEditor.h
    src/PluginProcessor.h
    # src/PluginParameters.h
    # sources
    src/PluginEditor.cpp
    src/PluginProcessor.cpp
    # src/PluginParameters.cpp
)
target_sources("${BaseTargetName}" PRIVATE ${SourceFiles})

juce_add_binary_data("${BaseTargetName}_Assets" SOURCES img/icon.png)

foreach(target ${FORMATS} "All")
    if(TARGET ${BaseTargetName}_${target})
        set_target_properties(${BaseTargetName}_${target} PROPERTIES
            FOLDER "Targets"          # Put plugin targets into a folder
            XCODE_GENERATE_SCHEME ON) # Build the target in Xcode
    endif()
endforeach()

set_target_properties("${BaseTargetName}_Assets" PROPERTIES FOLDER "Targets")

target_compile_definitions("${BaseTargetName}"
    PUBLIC
        JUCE_WEB_BROWSER=0
        JUCE_USE_CURL=0
        JUCE_VST3_CAN_REPLACE_VST2=0
        JUCE_DISPLAY_SPLASH_SCREEN=0)

set(JUCE_DEPENDENCIES
    juce::juce_audio_utils
    juce::juce_dsp)

set(ANO_MODULE_DEPENDENCIES
    ano_gui
    ano_processor)

target_link_libraries("${BaseTargetName}"
    PRIVATE
        "${BaseTargetName}_Assets"
        ${JUCE_DEPENDENCIES}
        ${ANO_MODULE_DEPENDENCIES}
    PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
        juce::juce_recommended_warning_flags)

###############################################################################
################################## Unit Tests #################################
###############################################################################

# include(CTest)
enable_testing()

set(TestFiles
    tests/Main.cpp
    tests/TestOne.cpp)

add_executable("${BaseTargetName}_tests" ${TestFiles})

target_include_directories("${BaseTargetName}_tests" 
    PRIVATE 
        ${CMAKE_CURRENT_SOURCE_DIR}/src)

target_link_libraries("${BaseTargetName}_tests" 
    PRIVATE 
        Catch2::Catch2 
        "${PROJECT_NAME}" 
        ${JUCE_DEPENDENCIES}
        ${ANO_MODULE_DEPENDENCIES})

set_target_properties("${BaseTargetName}_tests" 
    PROPERTIES 
        XCODE_GENERATE_SCHEME ON)

source_group(TREE 
    ${CMAKE_CURRENT_SOURCE_DIR}/tests PREFIX "" FILES ${TestFiles})

include(${Catch2_SOURCE_DIR}/contrib/Catch.cmake)
catch_discover_tests("${BaseTargetName}_tests")
