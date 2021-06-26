# Command for Mac
HOMEDIR='Documents/SourceControl/cTest'
PLUGNAME='plug-Example'

# remove built bundles

FOLDERPATH=Library/Audio/Plug-Ins/Components/${PLUGNAME}.component
if [ -d $HOME/${FOLDERPATH} ]; then
    rm -R $HOME/${FOLDERPATH}
    echo "$HOME/${FOLDERPATH} removed"
else
    echo "failed to find ${FOLDERPATH}"
fi

FOLDERPATH=Library/Audio/Plug-Ins/VST/${PLUGNAME}.vst
if [ -d $HOME/${FOLDERPATH} ]; then
    rm -R $HOME/${FOLDERPATH}
    echo "$HOME/${FOLDERPATH} removed"
else
    echo "failed to find ${FOLDERPATH}"
fi

FOLDERPATH=Library/Audio/Plug-Ins/VST3/${PLUGNAME}.vst3
if [ -d $HOME/${FOLDERPATH} ]; then
    rm -R $HOME/${FOLDERPATH}
    echo "$HOME/${FOLDERPATH} removed"
else
    echo "failed to find ${FOLDERPATH}"
fi

# remove auval file
FILE=Library/Audio/Plug-Ins/Components/auval_${PLUGNAME}.txt
if test -f $HOME/${FILE}; then
    rm $HOME/${FILE}
    echo "$HOME/${FILE} removed."
else
    echo "failed to find ${FILE}"
fi

# remove pluginval file
rm $HOME/Library/Audio/Plug-Ins/VST3/AnoesisAudio\ -\ ${PLUGNAME}*.txt

# remove standalone settings files
FILEPATH='Library/Application Support'
if test -f "$HOME/${FILEPATH}/${PLUGNAME}.settings"; then
    rm "$HOME/${FILEPATH}/${PLUGNAME}.settings"
    echo "$HOME/${FILEPATH}/${PLUGNAME}.settings removed"
else
    echo "failed to find $HOME/${FILEPATH}/${PLUGNAME}.settings"
fi

# remove builds in _builds folder

FOLDERPATH=$HOMEDIR/_builds/plug-Example/plug/plug-Example_artefacts/Debug/AU/${PLUGNAME}.component
if [ -d $HOME/${FOLDERPATH} ]; then
    rm -R $HOME/${FOLDERPATH}
    echo "$HOME/${FOLDERPATH} removed"
else
    echo "failed to find ${FOLDERPATH}"
fi

FOLDERPATH=$HOMEDIR/_builds/plug-Example/plug/plug-Example_artefacts/Debug/VST/${PLUGNAME}.vst
if [ -d $HOME/${FOLDERPATH} ]; then
    rm -R $HOME/${FOLDERPATH}
    echo "$HOME/${FOLDERPATH} removed"
else
    echo "failed to find ${FOLDERPATH}"
fi

FOLDERPATH=$HOMEDIR/_builds/plug-Example/plug/plug-Example_artefacts/Debug/VST3/${PLUGNAME}.vst3
if [ -d $HOME/${FOLDERPATH} ]; then
    rm -R $HOME/${FOLDERPATH}
    echo "$HOME/${FOLDERPATH} removed"
else
    echo "failed to find ${FOLDERPATH}"
fi

FOLDERPATH=$HOMEDIR/_builds/plug-Example/plug/plug-Example_artefacts/Debug/Standalone
if [ -d $HOME/${FOLDERPATH}/${PLUGNAME}.app ]; then
    rm -R $HOME/${FOLDERPATH}/${PLUGNAME}.app
    echo "$HOME/${FOLDERPATH}/${PLUGNAME} found and removed"
else
    echo "failed to find $HOME/${FOLDERPATH}/${PLUGNAME}"
fi

FILEPATH=$HOMEDIR/_builds/plug-Example/plug/plug-Example_artefacts/Debug/
if test -f "$HOME/${FILEPATH}/lib${PLUGNAME}_SharedCode.a"; then
    rm "$HOME/${FILEPATH}/lib${PLUGNAME}_SharedCode.a"
    echo "$HOME/${FILEPATH}/lib${PLUGNAME}_SharedCode.a removed"
else
    echo "failed to find $HOME/${FILEPATH}/lib${PLUGNAME}_SharedCode.a"
fi

FILEPATH=$HOMEDIR/_builds/plug-Example/plug/Debug/
if test -f "$HOME/${FILEPATH}/${PLUGNAME}_tests"; then
    rm -R "$HOME/${FILEPATH}/"
    echo "$HOME/${FILEPATH}/${PLUGNAME}_tests removed"
else
    echo "failed to find $HOME/${FILEPATH}/${PLUGNAME}_tests"
fi
