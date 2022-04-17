//#include <PluginProcessor.h>
#include <catch2/catch_all.hpp>

TEST_CASE("one is equal to one", "[dummy]")
{
    REQUIRE(1 == 1);
}

//AudioPluginAudioProcessor proc;
//
//TEST_CASE("Plugin instance name", "[name]")
//{
//    CHECK_THAT(proc.getName().toStdString(), Catch::Matchers::Equals("plug-Example"));
//}
