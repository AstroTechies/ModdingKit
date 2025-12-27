#include "ModDeployerCommands.h"

#define LOCTEXT_NAMESPACE "FModDeployerModule"

void FModDeployerCommands::RegisterCommands()
{
	UI_COMMAND(PluginAction, "Mod Deployer", "Open a helper tab for quickly deploying mods for debugging", EUserInterfaceActionType::Button, FInputChord());
	UI_COMMAND(PluginActionQuick, "Quick Deploy", "Quickly execute \"Run everything\" without needing the Mod Deployer tab open", EUserInterfaceActionType::Button, FInputChord(EKeys::F5));
}

#undef LOCTEXT_NAMESPACE
