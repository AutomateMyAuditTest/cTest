cmake_minimum_required(VERSION 3.21)

project(AnoTemplate VERSION 0.0.1)

set(CMAKE_XCODE_GENERATE_SCHEME OFF)

option(JUCE_ENABLE_MODULE_SOURCE_GROUPS "Show all module sources in IDE projects" ON)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/JUCE)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/Catch2)
juce_set_vst2_sdk_path(VST2_SDK)
add_subdirectory(ano_module)

add_subdirectory(plug-Example/plug)
