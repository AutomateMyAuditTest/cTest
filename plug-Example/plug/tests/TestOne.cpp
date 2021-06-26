#include "catch2/catch.hpp"
#include "../src/PluginProcessor.h"

TEST_CASE("one is equal to one", "[dummy]")
{
    CHECK(1 == 1);
}

AudioPluginAudioProcessor proc;

TEST_CASE("one is still equal to one", "[dummy2]")
{
    CHECK(1 == 1);
}

TEST_CASE("Plugin instance name", "[name]")
{
    CHECK_THAT(proc.getName().toStdString(), Catch::Equals("plug-Example"));
}
