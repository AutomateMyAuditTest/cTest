# Command for Mac
HOMEDIR='Documents/SourceControl/anoTemplates/cTest'
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

FOLDERPATH=$HOMEDIR/_builds/${PLUGNAME}/${PLUGNAME}.build
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
echo "Removing standalone settings files..."
FILEPATH='Library/Application Support'
if test -f "$HOME/${FILEPATH}/${PLUGNAME}.settings"; then
    rm "$HOME/${FILEPATH}/${PLUGNAME}.settings"
    echo "$HOME/${FILEPATH}/${PLUGNAME}.settings removed"
else
    echo "failed to find $HOME/${FILEPATH}/${PLUGNAME}.settings"
fi
