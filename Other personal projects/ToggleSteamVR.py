import questionary
import os
import time

#The program renames the "SteamVR" folder to "SteamVRa"
#This causes steam to not detect it, thus effectively disabling it.

#insert directory to that includes the SteamVR folder
SteamVRdir = "C:\\Program Files (x86)\\Steam\\steamapps\\common"

os.chdir(SteamVRdir)
if os.path.isdir("SteamVR"):
    print("SteamVR is currently enabled!")
    yn = questionary.confirm("Would you like to disable SteamVR?",qmark="#",default=True).ask()
    if yn == True:
        os.rename("SteamVR","SteamVRa")
        print("SteamVR successfully disabled. Closing in 2 seconds.")
        time.sleep(2)
    else:
        print("SteamVR remains active...")
elif os.path.isdir("SteamVRa"):
    print("SteamVR is currently disabled!")
    yn = questionary.confirm("Would you like to enable SteamVR?",default=True).ask()
    if yn == True:
        os.rename("SteamVRa","SteamVR")
        print("SteamVR successfully enabled. Closing in 2 seconds.")
        time.sleep(2)
    else:
        print("SteamVR remains disabled...")
else:
    print("SteamVR not found...")