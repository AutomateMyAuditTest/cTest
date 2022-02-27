'''
This script will remove the _builds directory and all of its contents.
'''

import os
import platform
import sys
import shutil
import glob
from pathlib import Path
from plugs import getPlugs

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

############################ built stuff ############################
try:
    os.system('cls' if os.name == 'nt' else 'clear')

    cmd = "echo 'Removing _builds '"
    os.system(cmd)

    if(platform_name == 'Darwin'):
        #### builds outside of _builds folder ####
        print('CLEAN STATUS removing builds in /Library/Audio/Plug-Ins')
        for key in plugs:
            # remove component in /Library/Audio/Plug-Ins
            path = home_path + \
                '/Library/Audio/Plug-Ins/Components/' + \
                plugs[key]['name'] + '.component'
            try:
                isdir = os.path.isdir(path)
                if isdir:
                    shutil.rmtree(path)
            except OSError as e:
                print("Error: %s : %s" % (path, e.strerror))
                sys.exit(1)
            # remove vst in /Library/Audio/Plug-Ins
            path = home_path + '/Library/Audio/Plug-Ins/VST/' + \
                plugs[key]['name'] + '.vst'
            try:
                isdir = os.path.isdir(path)
                if isdir:
                    shutil.rmtree(path)
            except OSError as e:
                print("Error: %s : %s" % (path, e.strerror))
                sys.exit(1)
            # remove vst3 in /Library/Audio/Plug-Ins
            path = home_path + '/Library/Audio/Plug-Ins/VST3/' + \
                plugs[key]['name'] + '.vst3'
            try:
                isdir = os.path.isdir(path)
                if isdir:
                    shutil.rmtree(path)
            except OSError as e:
                print("Error: %s : %s" % (path, e.strerror))
                sys.exit(1)
            # remove auval file in /Library/Audio/Plug-Ins
            file_name = home_path + '/Library/Audio/Plug-Ins/Components/auval_' + \
                plugs[key]['name'] + '.txt'
            try:
                isFile = os.path.isfile(file_name)
                if isFile:
                    os.remove(file_name)
            except OSError as e:
                print("Error: %s : %s" % (file_name, e.strerror))
                sys.exit(1)
            # remove pluginval file in /Library/Audio/Plug-Ins/VST3
            for file in os.listdir(home_path + '/Library/Audio/Plug-Ins/VST3/'):
                if file.startswith('AnoesisAudio - ' + plugs[key]['name']):
                    try:
                        os.remove(
                            home_path + '/Library/Audio/Plug-Ins/VST3/' + file)
                    except OSError as e:
                        print("Error: %s : %s" % (file_name, e.strerror))
                        sys.exit(1)
            # remove pluginval file in /Library/Audio/Plug-Ins/VST
            for file in os.listdir(home_path + '/Library/Audio/Plug-Ins/VST/'):
                if file.startswith('AnoesisAudio - ' + plugs[key]['name']):
                    try:
                        os.remove(
                            home_path + '/Library/Audio/Plug-Ins/VST/' + file)
                    except OSError as e:
                        print("Error: %s : %s" % (file_name, e.strerror))
                        sys.exit(1)
            # remove standalone settings files in /Library/Application Support
            file_name = home_path + '/Library/Application Support/' + \
                plugs[key]['name'] + '.settings'
            try:
                for f in glob.glob(file_name):
                    isFile = os.path.isfile(file_name)
                    if isFile:
                        os.remove(f)
            except OSError as e:
                print("Error: %s : %s" % (file_name, e.strerror))
                sys.exit(1)
            ####    remove the _builds folder     ####
            print('CLEAN STATUS removing the _builds folder')
            dir_path = current_path + '/_builds'
            isdir = os.path.isdir(dir_path)
            if isdir == True:
                try:
                    shutil.rmtree(dir_path)
                except OSError as e:
                    print("Error: %s : %s" % (dir_path, e.strerror))
                    sys.exit(1)

    elif(platform_name == 'Linux'):
        ####    remove the _builds folder     ####
        print('CLEAN STATUS removing the _builds folder')
        dir_path = current_path + '/_builds'
        isdir = os.path.isdir(dir_path)
        if isdir == True:
            try:
                shutil.rmtree(dir_path)
            except OSError as e:
                print("Error: %s : %s" % (dir_path, e.strerror))
                sys.exit(1)

    elif(platform_name == 'Windows'):
        ####    remove the _builds folder     ####
        print('CLEAN STATUS removing the _builds folder')
        dir_path = current_path + '/_builds'
        isdir = os.path.isdir(dir_path)
        if isdir == True:
            try:
                shutil.rmtree(dir_path)
            except OSError as e:
                print("Error: %s : %s" % (dir_path, e.strerror))
                sys.exit(1)

    else:
        raise ValueError(
            'Operating system not recognized by clean.py script.')

    cmd = "echo 'The _builds directory has been removed.'"
    os.system(cmd)
    sys.exit(0)

except OSError as e:
    print("Error: %s : %s" % (cmd, e.strerror))
    sys.exit(1)
