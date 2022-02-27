'''
This script will run unit tests on all plugins in this project.
The plugins must have already been built. To run, use
python3 scripts/tests.py
'''

import os
import platform
import sys
from pathlib import Path
from plugs import getPlugs
from functions import logcmd

# collect needed information
plugs = getPlugs()
platform_name = platform.system()
platform_release = platform.release()
current_path = os.getcwd()
home_path = str(Path.home())
python_version = 'python3'  # expect python3
pv = sys.version  # captures the python version number (2 or 3)
if pv.startswith('2.'):
    python_version = 'python'

try:
    f = open(current_path + '/_builds/cmakeprojecttype.txt', 'r')
    build_type = f.read()
except:
    build_type = 'Debug'
    raise Exception(
        'Something is wrong with project type. Running tests expecting Debug.')

########################### do the tests ############################
print('Testing is starting')
print("")

try:
    os.system('cls' if os.name == 'nt' else 'clear')

    ##############################################
    if(platform_name == 'Darwin'):
        logcmd(current_path, 'Start Darwin Validation\n')
        # -----> MAC Clean component register
        cmd = 'killall -9 AudioComponentRegistrar;'
        try:
            os.system(cmd)
            logcmd(current_path, cmd)
        except OSError as e:
            print("Error: %s" % (e.strerror))
            sys.exit(1)
        # -----> MAC auval
        for key in plugs:
            cmd = 'auval -v ' + plugs[key]['type'] + ' ' + plugs[key]['code'] + ' ' + \
                plugs[key]['manu'] + ' &> ' + home_path + \
                '/Library/Audio/Plug-Ins/Components/auval_' + \
                plugs[key]['name'] + '.txt'
            try:
                os.system(cmd)
                logcmd(current_path, cmd)
            except OSError as e:
                print("Error: %s" % (e.strerror))
                sys.exit(1)
        # -----> MAC pluginval - VST3
        for key in plugs:
            cmd = '/Applications/pluginval.app/Contents/MacOS/pluginval ' + \
                '--output-dir ' + home_path + '/Library/Audio/Plug-Ins/VST3 ' + \
                '--strictness-level 5 ' + \
                '--validate ' + home_path + '/Library/Audio/Plug-Ins/VST3/' + \
                plugs[key]['name'] + '.vst3' + \
                ' --validate-in-process || exit 1'
            try:
                os.system(cmd)
                logcmd(current_path, cmd)
            except OSError as e:
                print("Error: %s" % (e.strerror))
                sys.exit(1)
            except Exception as e:
                print("Error: %s" % (e.strerror))
                sys.exit(1)
        # -----> MAC pluginval - VST
        for key in plugs:
            cmd = '/Applications/pluginval.app/Contents/MacOS/pluginval ' + \
                '--output-dir ' + home_path + '/Library/Audio/Plug-Ins/VST ' + \
                '--strictness-level 5 ' + \
                '--validate ' + home_path + '/Library/Audio/Plug-Ins/VST/' + \
                plugs[key]['name'] + '.vst' + \
                ' --validate-in-process || exit 1'
            try:
                os.system(cmd)
                logcmd(current_path, cmd)
            except OSError as e:
                print("Error: %s" % (e.strerror))
                sys.exit(1)
            except Exception as e:
                print("Error: %s" % (e.strerror))
                sys.exit(1)
        # -----> MAC unit tests
        unit_test_file_paths = []
        for key in plugs:
            for root, dir, files in os.walk(current_path):
                for file_name in files:
                    if file_name == plugs[key]['name'] + '_tests':
                        unit_test_file_paths.append(os.path.join(
                            current_path, root, file_name))

        for cmd in unit_test_file_paths:
            try:
                os.system(cmd)
                logcmd(current_path, cmd)
            except OSError as e:
                print("Error: %s" % (e.strerror))
                sys.exit(1)

    ##############################################
    elif(platform_name == 'Linux'):
        # -----> Linux pluginval - VST3
        pluginval_location = ''
        for root, dir, files in os.walk(home_path):
            for f in files:
                if 'pluginval' in f:
                    pluginval_location = root + '/' + f

        pluginval_commands = []
        for key in plugs:
            for root, dir, files in os.walk(current_path):
                for d in dir:
                    if plugs[key]['name'] + '.vst3' in d:
                        ouput_dir = '--output-dir ' + root + ' '
                        strictness_level = '--strictness-level 5 '
                        vst3_path = '--validate ' + root + '/' + d + ' '
                        in_process = '--validate-in-process || exit 1'
                        command = pluginval_location + ' ' + ouput_dir + \
                            strictness_level + vst3_path + in_process
                        pluginval_commands.append(command)

        for cmd in pluginval_commands:
            try:
                os.system(cmd)
                logcmd(current_path, cmd)
            except OSError as e:
                print("Error: %s" % (e.strerror))
                sys.exit(1)
        # -----> Linux unit tests
        unit_test_file_paths = []
        for key in plugs:
            for root, dir, files in os.walk(current_path):
                for file_name in files:
                    if file_name == plugs[key]['name'] + '_tests':
                        unit_test_file_paths.append(os.path.join(
                            current_path, root, file_name))

        for cmd in unit_test_file_paths:
            try:
                os.system(cmd)
                logcmd(current_path, cmd)
            except OSError as e:
                print("Error: %s" % (e.strerror))
                sys.exit(1)

    ##############################################
    elif(platform_name == 'Windows'):
        # -----> Windows pluginval - VST3
        pluginval_location = ''
        for root, dir, files in os.walk(home_path):
            for f in files:
                if 'pluginval.exe' in f:
                    pluginval_location = root + '/' + f

        pluginval_commands = []
        for key in plugs:
            for root, dir, files in os.walk(current_path):
                for d in dir:
                    if plugs[key]['name'] + '.vst3' in d:
                        ouput_dir = '--output-dir ' + root + ' '
                        strictness_level = '--strictness-level 5 '
                        vst3_path = '--validate ' + root + '/' + d + ' '
                        in_process = '--validate-in-process || exit 1'
                        command = pluginval_location + ' ' + ouput_dir + \
                            strictness_level + vst3_path + in_process
                        pluginval_commands.append(command)

        for cmd in pluginval_commands:
            try:
                os.system(cmd)
                logcmd(current_path, cmd)
            except OSError as e:
                print("Error: %s" % (e.strerror))
                sys.exit(1)
        # -----> Windows pluginval - VST
        pluginval_location = ''
        for root, dir, files in os.walk(home_path):
            for f in files:
                if 'pluginval.exe' in f:
                    pluginval_location = root + '/' + f

        pluginval_commands = []
        for key in plugs:
            for root, dir, files in os.walk(current_path):
                for d in files:
                    if plugs[key]['name'] + '.dll' in d:
                        ouput_dir = '--output-dir ' + root + ' '
                        strictness_level = '--strictness-level 5 '
                        dll_path = '--validate ' + root + '/' + d + ' '
                        in_process = '--validate-in-process || exit 1'
                        command = pluginval_location + ' ' + ouput_dir + \
                            strictness_level + dll_path + in_process
                        pluginval_commands.append(command)

        for cmd in pluginval_commands:
            try:
                os.system(cmd)
                logcmd(current_path, cmd)
            except OSError as e:
                print("Error: %s" % (e.strerror))
                sys.exit(1)
        # -----> Windows unit tests
        unit_test_file_paths = []
        for key in plugs:
            for root, dir, files in os.walk(current_path):
                for file_name in files:
                    if file_name == plugs[key]['name'] + '_tests.exe':
                        unit_test_file_paths.append(os.path.join(
                            current_path, root, file_name))

        for cmd in unit_test_file_paths:
            try:
                os.system(cmd)
                logcmd(current_path, cmd)
            except OSError as e:
                print("Error: %s" % (e.strerror))
                sys.exit(1)

    ##############################################
    else:
        raise ValueError('Operating system not recognized by tests.py script.')

except OSError as e:
    print("Error: %s" % (e.strerror))
    sys.exit(1)
except Exception as e:
    print("Error: %s" % (e.strerror))
    sys.exit(1)
