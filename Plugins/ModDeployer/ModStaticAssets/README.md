# ModStaticAssets

This directory exists to provide the ability to manually include static files as part of your mod when deploying mods using the Mod Deployer plugin.

Place your static files within the `ModStaticAssets/<mod ID>` directory, and they will be included when a mod with that mod ID is packaged by the Mod Deployer.

You can also use this directory to bundle UE4SS mods for deployment (set the `enable_ue4ss` field to true in metadata.json and include a directory at `ModStaticAssets/<mod ID>/UE4SS`), but handling for UE4SS mods is not included with the plugin. You should install UE4SS and [the AutoIntegrator mod](https://thunderstore.io/c/astroneer/p/atenfyr/AutoIntegrator/) to automatically deploy bundled UE4SS mods on game launch, or otherwise load the packaged mod manually using AstroModLoader Classic.
