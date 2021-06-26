# Anoesis Plugin Group Structure Template - using Catch2

## To pull this repository

```
git clone --recurse-submodules https://github.com/MyPublicGitHubAcct/cTest.git
```

# TODO
* Put scripts for build, clean, and validate in plug-Example.
* Put compiling of AudioPluginHost in a script on each plat (post-runcmake).
* View and Processor files included and working.
* Auto compile and load plug in a host.
* Develop tests to be run for current files.
* Add visualizations project
* Make ano_module a submodule
* Use GitLab...
  * [GitLab](https://www.lambdatest.com/blog/use-gitlab-ci-to-run-test-locally/)
  * [Using with GoogleTest](https://raymii.org/s/tutorials/Cpp_project_setup_with_cmake_and_unit_tests.html)
  * [Offline use](https://docs.gitlab.com/ee/topics/offline/quick_start_guide.html)
* For Linux build - add these to CMakeLists.txt ??? - [source](https://forum.juce.com/t/cant-run-apps-ubuntu-21-04/46645):
	* CXXFLAGS=-fno-pie
	* LDFLAGS=-fno-pie
* Upgrade Catch2 to version 3.x (when it is officially released)

# Submodules

* Use the -b flag to choose the branch to use.

## Submodule for JUCE

```
git submodule add -b develop https://github.com/juce-framework/JUCE.git
```

## To udpate Submodules

```
git submodule update
```

## To find the built files -

#### Mac
* test executable is in "_builds/plug-Example/plug/Debug"
* plugins are in "_builds/plug-Example/plug/AudioPluginExample_artefacts/Debug"

#### Linux
* test executable is in "_builds\plug-Example\plug\"
* plugins are in "_builds\plug-Example\plug\AudioPluginExample_artefacts"

#### Windows
* test executable is in "_builds\plug-Example\plug\Debug"
* plugins are in "_builds\plug-Example\plug\AudioPluginExample_artefacts\Debug"

## Linux setup

* Install all updates for Ubuntu
* Power off
* Make sure that the shared folder & other VirtualBox config is good.
* Insert Guest Additions CD Image... (Under VirtualBox Devices menu)
* Open the terminal with Cntrl+Alt+T and make it a favorite
* Update apt

```
sudo apt update  
sudo apt upgrade
```

### Install ulauncher -
```
sudo add-apt-repository ppa:agornostal/ulauncher
sudo apt update
sudo apt install ulauncher
```

### Install other dependencies

```
sudo apt-get install build-essential curl libfreetype6-dev libssl-dev libx11-dev libxinerama-dev libxcursor-dev mesa-common-dev libasound2-dev freeglut3-dev libxcomposite-dev libjack-dev libxrandr-dev webkit2gtk-4.0

sudo apt-get install -y ninja-build
sudo snap install cmake --classic
sudo apt install git-all
```

* Install VS CODE from Ubuntu Software thingy (vscode) & open from terminal
* Install the vscode C++ tools and CMake tools
* Download the project and build it

```
mkdir Documents/SourceControl
cd Documents/SourceControl
git clone --recurse-submodules https://github.com/MyPublicGitHubAcct/anoTemplate.git
```

* To build after running cmake -

```
cmake --build _builds --config Debug
```

## Run the test executable

* To run the testing executable on Mac
```
cd $HOME/Documents/SourceControl/anoTemplate/_builds/plug-Example/plug/Debug
./AudioPluginExample_tests
```

* To run the testing executable on Linux
```
cd /$HOME/Documents/SourceControl/anoTemplate/_builds/plug-Example/plug
./AudioPluginExample_tests
```

* To run the test executable on Windows
```
cd $HOME\Documents\SourceControl\anoTemplate\_builds\plug-Example\plug\Debug
.\AudioPluginExample_tests.exe
```

# Future

## Linux
* Support LV2 - see [this article](https://jatinchowdhury18.medium.com/building-lv2-plugins-with-juce-and-cmake-d1f8937dbac3). Also, see [the website](https://lv2plug.in/).

# Sources
* [Testing](https://snorristurluson.github.io/Catch2/)
* [Catch2 docs](https://github.com/catchorg/Catch2/tree/devel/docs)
* [pamplejuce](https://github.com/sudara/pamplejuce)
