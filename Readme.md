# Anoesis Plugin Group Structure Template - using Catch2

The main purpose of this repository is to act as a cross-platform template for project lines. The inclusion of individual plugin projects should not require any additions to the items in the scripts folder except for the 'plugs.py' file.

### To download this template and use for a project (on mac)

* Install Catch2 (instructions below)
* Clone this repository to your system (using the command below).
* Change "cTest" to SOME_NEW_NAME.
* Delete the .git folder and the .gitmodules file.
* Delete the JUCE folder (which should be empty).
* ```git init```
* Run the cmake, build, tests, and clean scripts while checking that they are functioning properly. See the section **How the build system works** below.
* Make a commit to the local git repository (e.g. 'init commit').
* Create github repository (if desired) with same name, and follow their instructions.
* Rename plugin project folder(s).
* Update scripts/plugs.py to represent all actual plugin projects now included.
* Make the plugin projects into whatever you want them to be.

```
git clone https://github.com/MyPublicGitHubAcct/cTest.git
```

or, to get the submodule...(not recommended)

```
git clone --recurse-submodules https://github.com/MyPublicGitHubAcct/cTest.git
```

# TODO
* Use what is in Github Actions locally (e.g., ctest to run tests) - do in CICDExample first!
* Make Github Actions include tests using Pluginval.
* Rename project from cTest to ...?
* Make GUI scale the right way. See [this](https://forum.juce.com/t/current-advised-way-to-do-plugin-editor-contents-scaling/48044/10)
* plug-Example-syn: use svg for a knob, add svg background, add svg logo
* plug-Example-fx: Make use svgs for background, knob, and logo.
* tests for all plugs - various errors to clean up.
* Make plug-Example-sam to show how to make a sampler instrument?
* Make plug-Example-mpe to show how to make an MPE instrument?
* Windows: Add build option to create VisualStudio files that then use Ninja?
* Linux: During build, copy plugs to $HOME/.vst3
* Patch library
* User preferences
* Add a modulation source, LFO?
* Modulation matrix
* Make ano_module a submodule
* Use GitLab...
  * [GitLab](https://www.lambdatest.com/blog/use-gitlab-ci-to-run-test-locally/)
  * [Using with GoogleTest](https://raymii.org/s/tutorials/Cpp_project_setup_with_cmake_and_unit_tests.html)
  * [Offline use](https://docs.gitlab.com/ee/topics/offline/quick_start_guide.html)
* CI: Testing - need to deal with return codes and their impact on next steps.
* CI: Download pluginval each time run? Maybe check if have right version instead them determine if need to download?  Their [guidance](https://github.com/Tracktion/pluginval/blob/develop/docs/Adding%20pluginval%20to%20CI.md) suggests this.

# Unit testing
* Examples - [TestsTalk](https://github.com/Sinecure-Audio/TestsTalk.git) and [UnitsTalk](https://github.com/Sinecure-Audio/UnitsTalk.git). Also helpful -
  * https://youtu.be/QuW6omL-LkQ
  * https://github.com/Sinecure-Audio/Units.git
  * https://github.com/sudara/melatonin_audio_block_test_helpers.git

# Installing Catch2
* See instructions here -> https://github.com/catchorg/Catch2/blob/devel/docs/cmake-integration.md#installing-catch2-from-git-repository
```
$ git clone https://github.com/catchorg/Catch2.git
$ cd Catch2
$ cmake -Bbuild -H. -DBUILD_TESTING=OFF
$ sudo cmake --build build/ --target install
```

# Submodules

* Use the -b flag to choose the branch to use.

## Submodules for JUCE and Catch2

```
git submodule add -b develop https://github.com/juce-framework/JUCE.git

git submodule add -b devel https://github.com/catchorg/Catch2.git
```

## To udpate Submodules

```
git submodule update
```

### python
* to configure python tools in vs code,
  * On mac, there is a venv, so need to update config near the bottom of Python extension for Visual Studio Code settings.

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

This can also be done in one line, like...

```
sudo apt update && sudo apt upgrade
```

### Install other dependencies

```
sudo apt-get install build-essential curl libfreetype6-dev libssl-dev libx11-dev libxinerama-dev libxcursor-dev mesa-common-dev libasound2-dev freeglut3-dev libxcomposite-dev libjack-dev libxrandr-dev webkit2gtk-4.0

sudo apt-get install -y ninja-build
sudo snap install cmake --classic
sudo apt install git-all
sudo apt install clang
sudo apt install curl
```

* Install VS CODE from Ubuntu Software thingy (vscode) & open from terminal
* Install the vscode C++ tools and CMake tools
* Download the project and build it

```
mkdir Documents/SourceControl
cd Documents/SourceControl
git clone --recurse-submodules https://github.com/MyPublicGitHubAcct/cTest.git
```

### Pluginval
* Get from [Traktion's github](https://github.com/Tracktion/pluginval) and install in $HOME/Documents/Validators

### Ubuntu Cleaner
* To clean caches.

```
sudo apt install software-properties-common
sudo add-apt-repository ppa:gerardpuig/ppa
sudo apt update
sudo apt install ubuntu-cleaner
```

## Windows setup
* Get from [Traktion's github](https://github.com/Tracktion/pluginval) and install in $HOME/Documents/Validators

### Install clang in Visual Studio (could do it a different way, and don't *need* VS...)
* [Follow this](https://docs.microsoft.com/en-us/cpp/build/clang-support-msbuild?view=msvc-160)
* In VS2019, click on Tools > Get Tools and Features > Individual Components, then search for clang and select all.
* In VS2019, To configure a Visual Studio project to use Clang, right-click on the project node in Solution Explorer and choose Properties. Typically, you should first choose All configurations at the top of the dialog. Then, under General > Platform Toolset, choose LLVM (clang-cl) and then OK.
* The clang executables are in 'C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\Llvm\x64\bin\'.

### Install CMake
* For mac, use ```brew install cmake```.
* For linux, see 'Install other dependencies' under 'Linux setup' above.
* For windows, use a precompiled binary from https://cmake.org

### Install Ninja
* Download the executable from [Ninja build system](https://ninja-build.org/) and unzip it to c:/Ninja.
* Also, [see](https://www.boden.io/getting-started/installing_dependencies/windows/), also, [see](https://github.com/rwols/CMakeBuilder/wiki/Ninja-for-Windows-Installation-Instructions)
* Configure to use CMake, clang, Ninja [see](https://stackoverflow.com/questions/46553436/building-with-cmake-ninja-and-clang-on-windows) - see Simon's answer; this has been roughly approximated in runcmakeWindows.ps1.
* See [this thread](https://forum.juce.com/t/cant-build-juceaide-compilers-found-and-then-not-found/46700)

#### Add to path
* [instructions source](https://www.architectryan.com/2018/03/17/add-to-the-path-on-windows-10/)
* Type 'env' in the search & Click the “Environment Variables…” button on *System Properties*, *Advanced*.
* Under the “System Variables” section (the lower half), find the row with “Path” in the first column, and click edit and add the following -
  * 'C:\Ninja'
  * 'C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\Llvm\x64\bin'

#### Set environment variables
* [instructions source](https://www.architectryan.com/2018/08/31/how-to-change-environment-variables-on-windows-10/)
* Type 'env' in the search & Click the “Environment Variables…” button on *System Properties*, *Advanced*.
* Under the “System Variables” section (the lower half), find the row with “Path” in the first column, and click New and add the following -
  * RC = llvm-rc.exe
  * CC = clang.exe
  * CXX = clang++.exe
* To see all environment variables, use the 'Get-ChildItem Env:' command.

### Oh, and...
* Need to add -DCMAKE_LINKER:PATH="C:\WHATEVERPATH\lld-link.exe" to the cmake command.

## Run the *test* executable

* To run the testing executable on Mac
```
cd $HOME/Documents/SourceControl/gTest/_builds/plug-Example/plug/Debug
./AudioPluginExample_tests
```

* To run the testing executable on Linux
```
cd /$HOME/Documents/SourceControl/gTest/_builds/plug-Example/plug
./AudioPluginExample_tests
```

* To run the test executable on Windows
```
cd $HOME\Documents\SourceControl\jTest\_builds\plug-Example\plug\Debug
.\AudioPluginExample_tests.exe
```

## Mac
* On mac, there is a Python environment installed, which the script 'macrp.sh' is used to enter. It was installed doing this -

```
python3 -m venv venv
```

* To activate it, use

```
source venv/bin/activate
```

* To install what is needed
```
python3 -m pip install -U pip
pip install wheel
pip install -U jupyterlab ipywidgets pandas numpy scipy matplotlib
pip install ipympl
```

* To make requirements.txt, in .../gTest, run

```
pip freeze > requirements.txt
```

* To update pip

```
python3 -m pip install --upgrade pip
```

* To run a notebook
```
jupyter notebook
```

* To use requirements.txt to recreate the environment

```
python3 -m venv venv
source venv/bin/activate
python3 -m pip install --upgrade pip
python3 -m pip install -r requirements.txt
```

* To upgrade all packages...

```
pip list --outdated --format=freeze | grep -v '^\-e' | cut -d = -f 1  | xargs -n1 pip install -U
pip freeze > requirements.txt
```

* Also, when using xcode it may be needed to change config to be able to clean. Use
```
Set Xcode > Preferences > Locations > Advanced > Build Locations to “Unique”
```

TODO
# MPE synth
* Use MPESynthesiser (rather than Synthesiser) & MPESynthesiserVoice (rather than Voice)  are subclassed.
* https://youtu.be/Xqj8BVdI0Tg
* https://github.com/swirkes/MPESynthesiserExploration.git
* https://github.com/alponet/mpe_woksizer.git
* https://github.com/ncblair/JUCE_Neural_Granulator.git
* https://github.com/jpcima/Hera

TODO
# Test Driven Development
* JUCE demo - https://youtu.be/QuW6omL-LkQ, https://github.com/Sinecure-Audio/TestsTalk/tree/ADC_Talk

## Default plugin locations

### Mac
* /Library/Audio/Plug-Ins/...
* $HOME/Library/Audio/Plug-Ins/...

### Linux
* VST3
  * /usr/lib64/vst3
* LXVST
  * usr/lib/lxvst
  * usr/local/lib/lxvst
* LADSPA
  * /usr/lib/ladspa/
  * /usr/local/lib/ladspa/
* LVST
  * /usr/lib/lv2/
  * /usr/local/lib/lv2/

### Windows
* VST2
  * C:\Program Files\VSTPlugins
* VST3
  * C:\Program Files\Common Files\VST3
* Standalone
  * C:\Program Files\AnoesisAudio\Standalone

# How the local build system works
* run cmake like ``` python3 scripts/cmake.py ```
* run build like ``` python3 scripts/build.py ```
* run tests like ``` python3 scripts/tests.py ```
* run clean like ``` python3 scripts/clean.py ```

# How the Github build system works
* build_debug.yml is run when the tag is updated as below

```
git add --all
git commit -m "<text>"
git tag <tagname>
git push origin --tags
```

# To add new plugin projects
* Note: In a real use of this framework, plug-Example-fx and plug-Example-syn would be removed, and copies of these would be starting points for real plugin projects.
* Update both CMakeLists documents to have the correct plugin (folder) name.
* Update the plugin project CMakeLists document to have the correct plugin id.
* Update scripts/plugs.py to reflect what is true.

# Future topics

## Copy protection
*  KVR article - [More copy protection...](https://www.kvraudio.com/forum/viewtopic.php?f=33&t=472847)

## GUI
* KVR article - [Ui Design Tutorials?](https://www.kvraudio.com/forum/viewtopic.php?f=33&t=541318)

# Known Challenges and How to Fix Them
* NaNs, Infs, and Subnormals in buffers
  * Make sure that buffers are cleared before filled.
  * Make sure that parameter ranges do not allow for out of range floats, cause by e.g. filters blowing up.

# Other research and intersting stuff...
* Coursera class - [Audio Signal Processing for Music Applications](https://www.coursera.org/learn/audio-signal-processing/home/welcome)
* Python tutorial 1 - [ADSP_Tutorials](https://github.com/GuitarsAI/ADSP_Tutorials)
* Python tutorial 2 - [MRSP_Notebooks](https://github.com/GuitarsAI/MRSP_Notebooks)
* Open source plugs - [OpenAudio](https://github.com/webprofusion/OpenAudio)
* Open source plug 1 - [BlackBird](https://github.com/khrykin/BlackBird/)
* VCV Rack plug [library](https://github.com/VCVRack/library/tree/v1/repos)
* Python Filter Design Analysis Tool [code](https://github.com/chipmuenk/pyfda)

# TODO - cTest framework - future
* Security - [python](https://realpython.com/absolute-vs-relative-python-imports/)
* Envelopes - https://www.kvraudio.com/forum/viewtopic.php?f=33&t=567563
* Support LV2 - see [this article](https://jatinchowdhury18.medium.com/building-lv2-plugins-with-juce-and-cmake-d1f8937dbac3). Also, see [the website](https://lv2plug.in/).
* Work out how to protect the plugs. The strategy can employ ideas metioned [here](https://www.kvraudio.com/forum/viewtopic.php?f=33&t=472847&start=360)

## Linux
* Support LV2 - see [this article](https://jatinchowdhury18.medium.com/building-lv2-plugins-with-juce-and-cmake-d1f8937dbac3). Also, see [the website](https://lv2plug.in/).

# Sources
* [Testing](https://snorristurluson.github.io/Catch2/)
* [Catch2 docs](https://github.com/catchorg/Catch2/tree/devel/docs)
* [pamplejuce](https://github.com/sudara/pamplejuce)
