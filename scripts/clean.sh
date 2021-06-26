# remove all plugins
clear

HOMEDIR='Documents/SourceControl/anoTemplates/cTest'
PROJECT_1='plug-Example'

echo "================================"
echo "Removing old build files, compiles, and test results..."
echo ""
echo "$HOME/${HOMEDIR}/${PROJECT_1}/plug/scripts/clean.sh"
sh $HOME/${HOMEDIR}/${PROJECT_1}/plug/scripts/clean.sh
echo ""
echo "Removing _builds"
rm -fR _builds

if [ -d $HOME/${HOMEDIR}/_builds ]; then
    rm -fR $HOME/${HOMEDIR}/_builds
    echo "$HOME/${HOMEDIR}/_builds removed"
else
    echo "failed to find $HOME/${HOMEDIR}/_builds"
fi

echo "clean.sh complete"
