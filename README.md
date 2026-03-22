# Astroneer ModdingKit

This is an SDK for modding Astroneer. It was last updated for Astroneer version 1.36.42.0 (MEGATECH).

## Usage Guide
Visit the [astroneermodding.readthedocs.io website](https://astroneermodding.readthedocs.io/en/latest/guides/kitSetup.html) for more information on using this kit.

## Linux Usage
It is possible to build the Unreal Engine for Linux (Ubuntu) and use the Modding Kit to develop mods. Please note that this is a very advanced topic. You can follow the following instructions:

1. Download the source code for the Unreal Engine 4.27. Follow this guide: https://dev.epicgames.com/documentation/en-us/unreal-engine/downloading-source-code-in-unreal-engine
    - You can clone the Unreal Engine source code for 4.27 by executing the following on the command line: `git clone -b 4.27 https://github.com/EpicGames/UnrealEngine.git`

2. Build the engine. Follow this guide: https://github.com/EpicGames/UnrealEngine/blob/4.27/Engine/Build/BatchFiles/Linux/README.md

3. In your directory of choice, execute `git clone https://github.com/AstroTechies/ModdingKit.git && cd ModdingKit`

4. Execute `/path/to/your/engine/directory/Engine/Build/BatchFiles/RunUAT.sh BuildCookRun -Build -Project=$(pwd)/Astro.uproject` on the command line. Replace `/path/to/your/engine/directory/` with the root path of your built copy of the Unreal Engine.

5. Launch the Unreal Editor as normal. If desired, you can do this either via the graphical user interface or via the command line: `/path/to/your/engine/directory/Engine/Binaries/Linux/UE4Editor $(pwd)/Astro.uproject`

## Contributions
Please feel free to submit issues or pull requests to this project. It is requested that you modify the LICENSE.md file as part of your pull request to provide a license agreement for any files or directories that you contribute to the project.

## Kit Generation Guide
If you are interested in re-generating the Source directory on your own, e.g. for updating it to a future version, the process is as follows. This is not needed to make mods, and should only be done by advanced users.
1. Dump a set of UHT-compatible headers with UE4SS. You may wish to reference this guide for further information: [https://docs.ue4ss.com/guides/generating-uht-compatible-headers.html](https://docs.ue4ss.com/guides/generating-uht-compatible-headers.html).

2. Build and execute the [the UE4GameProjectGenerator commandlet](https://github.com/Buckminsterfullerene02/UE4GameProjectGenerator) on 4.27 with the dumped UE4SS headers, an Astro.upluginmanifest file extracted from an Astroneer game .pak file, and the .uproject file provided in this repository. You may need to modify the Astro.upluginmanifest file by hand to remove the AstroTests plugin.

3. Execute the process_game_dump.py file in this repository with the game project directory you specified in the previous step as the first parameter:

```sh
python process_game_dump.py <game project directory from previous step>
```

4. You're done!
