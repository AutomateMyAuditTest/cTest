HOMEDIR='Documents/SourceControl/wpfxPlugs'
PLUGNAME='plug-Exmample'
PLUGSCHEME='plug-Exmample_All'
GTEST='googletest-distribution'
TESTSCHEME='plug-Exmample_tests'

cd $HOME/${HOMEDIR}/_builds/${PLUGNAME}/plug
xcodebuild -project ${PLUGNAME}.xcodeproj -scheme ${PLUGSCHEME} -configuration Release

FILENAME="libgtest.a"
FILEPATH="$HOME/${HOMEDIR}/_builds/lib/Debug/${FILENAME}"
if [ ! -f "${FILEPATH}" ]; then
    cd $HOME/${HOMEDIR}/_builds/googletest
    xcodebuild -project ${GTEST}.xcodeproj
fi

cd $HOME/${HOMEDIR}/_builds/${PLUGNAME}/plug
xcodebuild -project ${PLUGNAME}.xcodeproj -scheme ${TESTSCHEME} -configuration Release
