HOMEDIR='Documents/SourceControl/wpfxPlugs'
PLUGNAME='plug-Example'
PLUGSCHEME='plug-Example_All'
GTEST='googletest-distribution'
TESTSCHEME='plug-Example_tests'

cd $HOME/${HOMEDIR}/_builds/${PLUGNAME}/plug
xcodebuild -project ${PLUGNAME}.xcodeproj -scheme ${PLUGSCHEME} -configuration Debug

FILENAME="libgtestd.a"
FILEPATH=$HOME/${HOMEDIR}/_builds/lib/Debug/${FILENAME}
if [ ! -f "${FILEPATH}" ]; then
    cd $HOME/${HOMEDIR}/_builds/googletest
    xcodebuild -project ${GTEST}.xcodeproj
fi

cd $HOME/${HOMEDIR}/_builds/${PLUGNAME}/plug
xcodebuild -project ${PLUGNAME}.xcodeproj -scheme ${TESTSCHEME} -configuration Debug
