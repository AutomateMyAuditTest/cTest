# run tests mac
HOMEDIR='/Documents/SourceControl/anoTemplates/cTest'
PLUGFOURCHARCODE='Ato1'
PLUGNAME='plug-Example'
PLUGMANUFACTURERCODE='Anoe'

echo "Anoesis validation running for ${PLUGNAME}"

sleep 3;

killall -9 AudioComponentRegistrar;

sleep 3;

# run auval
auval -v aufx ${PLUGFOURCHARCODE} ${PLUGMANUFACTURERCODE} &> $HOME/Library/Audio/Plug-Ins/Components/auval_${PLUGNAME}.txt
echo "${PLUGNAME} auval completed"

sleep 3;

# run pluginval on VST3
/Applications/pluginval.app/Contents/MacOS/pluginval --output-dir $HOME/Library/Audio/Plug-Ins/VST3 --strictness-level 5 --validate $HOME/Library/Audio/Plug-Ins/VST3/${PLUGNAME}.vst3
echo "${PLUGNAME} pluginval completed"

# run unit tests
echo ""
echo "$HOME/${HOMEDIR}/_builds/${PLUGNAME}/plug/Debug/${PLUGNAME}_tests"
echo ""
$HOME/${HOMEDIR}/_builds/${PLUGNAME}/plug/Debug/${PLUGNAME}_tests
echo "${PLUGNAME} unit test completed"
echo "Anoesis validation for ${PLUGNAME} done"
