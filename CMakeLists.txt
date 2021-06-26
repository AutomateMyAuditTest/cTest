cmake_minimum_required(VERSION 3.18.4)

###############################################################################
#############################   Project settings   ############################
###############################################################################

project(AnoTemplate VERSION 0.0.1)

###############################################################################
##############################   Subdirectories   #############################
###############################################################################

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/JUCE)
juce_set_vst2_sdk_path(VST2_SDK)
add_subdirectory(ano_module)

Include(FetchContent)
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        v2.13.6)
FetchContent_MakeAvailable(Catch2)

add_subdirectory(plug-Example/plug)
