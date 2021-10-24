# ModdingKit
A collection of reconstructed Astroneer proxy blueprints and source files used for creating custom mod blueprints that interact with elements of the game itself. It is not a perfect solution, but it gets the job done.

## Install Unreal Engine

Install Unreal Engine version `4.23.1`

You will be prompted to also install Visual Studio 2017. When you do you also need to install "Visual c++ tools for CMake and Linux" or you will later encounter a misleading "ERROR: Visual Studio 2017 requires the Universal CRT to be installed."

## Create a new mod project

Create a new unreal engine project for your mod. Make a blank project with no starter material. If you can, avoid using a path or project name with spaces in it.

Copy the `Content` and `Source` folders from the modding kit into the root directory of your project - the same folder that contains the `.uproject` file.

The blueprint files will not open yet in the unreal editor. They need the proxy source files to be built first.

Close unreal editor. In windows explorer right click on the `.uproject` file and select "Generate Visual Studio project files".

Open the generated visual studio `.sln` and build it.

Open the `.uproject` file in a text editor and add a module for the built proxies. It should look like this:

```
{
	"FileVersion": 3,
	"EngineAssociation": "4.23",
	"Category": "",
	"Description": "",
	"Modules": [
		{
			"Name": "Astro",
			"Type": "Runtime",
			"LoadingPhase": "Default"
		}
	]
}
```

Re-open unreal engine. You should now be able to explore most of the content, including the blueprints.

Open or create `Config\Windows\Engine.ini` in the project folder and add the following to it:

```
[Core.System]
UseSeparateBulkDataFiles=False

[/Script/Engine.StreamingSettings]
s.EventDrivenLoaderEnabled=False
```


## Cook and package a mod

The following examples use unreal engine installed in `E:\Unreal\UE_4.23` and an unreal engine project `E:\AstroneerMods\ExampleProject\ExampleProject.uproject`. Most unreal engine commands require absolute paths to work. Replace `E:\AstroneerMods\ExampleProject` with the path to your project and `ExampleProject` with the name of your project.

These examples cook and package the `Content/Examples/TrashCanMod`

### Metadata and packaging list

Create a metadata file to describe your mod to [AstroModLoader](https://github.com/AstroTechies/AstroModLoader).

```
{
    "name": "TrashCan Example Build",
    "mod_id": "TrashCanExampleBuild",
    "description": "Adds a trash can to the game which destroys all items placed into it.",
    "author": "Originally Atenfyr",
    "version": "0.1.0",
    "sync": "serverclient",
    "homepage": "https://atenfyr.com/astromods",
    "item_list_entries": {
        "/Game/Items/ItemTypes/MasterItemList": {
            "ItemTypes": [
                "/Game/Examples/TrashCanMod/TrashCan_IT"
            ]
        },
        "/Game/Components_Small/Printer_Breadboards_T1": {
            "PrinterComponent.Blueprints": [
                "/Game/Examples/TrashCanMod/TrashCan_BP"
            ]
        }
    }
}
```

Save it in the root project folder as `metadata.json`

Create an UnrealPak response file that lists what should be included in the `.pak` file. It includes all the cooked files under `Content/Examples/TrashCanMod` and the `metadata.json` file. The `../../../` are an unreal engine quirk, and do not depend on where your project is.

```
"E:\AstroneerMods\ExampleProject\Saved\Cooked\WindowsNoEditor\ExampleProject\Content\Examples\TrashCanMod\*.*" "../../../Astro/Content/Examples/TrashCanMod/*.*" -compress
"E:\AstroneerMods\ExampleProject\metadata.json" "../../../metadata.json" -compress
```

Save it in the root project folder as `paklist.txt`

UnrealPak can move but not rename files, so if you need `metadata.json` files for more than one mod in your project you will need to organize them in separate folders.

### Cooking and packaging batch file

Create a batch file to cook and package your mod. Change the `PROJECTPATH`, `PROJECTNAME`, `MOD_ID`, and `VERSION` to match your mod. Change `MODCONTENTPATH` to the folder that contains all of your mod's content.

```
set PROJECTROOT=E:\AstroneerMods\ExampleProject
set PROJECTNAME=ExampleProject
set MODCONTENTPATH=Content\Examples\TrashCanMod

set MOD_ID=TrashCanExampleBuild
set VERSION=0.1.0

set UE_PATH=E:\Unreal\UE_4.23

set PAKLIST="%PROJECTROOT%\paklist.txt"
set PROJECTFILE="%PROJECTROOT%\%PROJECTNAME%.uproject"
set PAKFILE="%PROJECTROOT%\Build\000-%MOD_ID%-%VERSION%_P.pak"

"%UE_PATH%\Engine\Binaries\Win64\UE4Editor-Cmd.exe" %PROJECTFILE% -run=Cook^
 -TargetPlatform=WindowsNoEditor^
 -CookDir="%PROJECTROOT%\%MODCONTENTPATH%"^
 -skipeditorcontent -fileopenlog^
 -unversioned -ini:Game:[/Script/UnrealEd.ProjectPackagingSettings]:BlueprintNativizationMethod=Disabled^
 -abslog="%PROJECTROOT%\Saved\Logs\manualcook.txt" -stdout -unattended -NoLogTimes -UTF8Output

"%UE_PATH%\Engine\Binaries\Win64\UnrealPak.exe" %PAKFILE% -create=%PAKLIST% -compress

"%UE_PATH%\Engine\Binaries\Win64\UnrealPak.exe" %PAKFILE% -List
```

Run the batch file to cook and package your mod. The final listing of package contents for the trash can mod should look simmilar to this:

```
LogPakFile: Display: Using command line for crypto configuration
LogPakFile: Display: Added 0 entries to add to pak file.
LogPakFile: Display: Mount point ../../../
LogPakFile: Display: "Astro/Content/Examples/TrashCanMod/Materials/M_TrashCan.uasset" offset: 0, size: 28696 bytes, sha1: 03BF3404E2F1439525EEBA9DDC34E3B793D8A531, compression: Zlib.
LogPakFile: Display: "Astro/Content/Examples/TrashCanMod/Models/trashcan.uasset" offset: 28769, size: 74336 bytes, sha1: D74CFE945A2CECCCF244FA4F73ABE8C101ADEE48, compression: Zlib.
LogPakFile: Display: "Astro/Content/Examples/TrashCanMod/Models/trashcan_Catalog.uasset" offset: 103210, size: 73870 bytes, sha1: 836FEFCE937EDC6C22E64C4D739F70400A2950C6, compression: Zlib.
LogPakFile: Display: "Astro/Content/Examples/TrashCanMod/TrashCan_BP.uasset" offset: 177185, size: 2954 bytes, sha1: B7C4C287E9371F1ECB8CC6A8CE58AA349E83AD0D, compression: Zlib.
LogPakFile: Display: "Astro/Content/Examples/TrashCanMod/TrashCan_IT.uasset" offset: 180212, size: 1493 bytes, sha1: 38F04CAB736FD06A7FD6F2F73A43A5AE93940ABA, compression: Zlib.
LogPakFile: Display: "Astro/Content/Examples/TrashCanMod/TrashCanSlot.uasset" offset: 181778, size: 2839 bytes, sha1: AE92403C7BBA41A4355DD332618C2C7EFC603942, compression: Zlib.
LogPakFile: Display: "metadata.json" offset: 184690, size: 328 bytes, sha1: 634F44F4756BCA22465DB559211C01598522475B, compression: Zlib.
LogPakFile: Display: 7 files (184516 bytes), (0 filtered bytes).
LogPakFile: Display: Unreal pak executed in 0.001545 seconds
```

## Test the mod

Install the built mod package located in `E:\AstroneerMods\ExampleProject\Build\` with [AstroModLoader](https://github.com/AstroTechies/AstroModLoader) and try out the mod.

