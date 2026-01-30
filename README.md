# Astroneer ModdingKit

This is an SDK for modding Astroneer. It was last updated for Astroneer version 1.36.42.0 (MEGATECH).

## Usage Guide
Visit the [astroneermodding.readthedocs.io website](https://astroneermodding.readthedocs.io/en/latest/guides/kitSetup.html) for more information on using this kit.

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
