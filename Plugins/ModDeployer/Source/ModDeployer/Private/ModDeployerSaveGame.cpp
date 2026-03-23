#include "ModDeployerSaveGame.h"

UModDeployerSaveGame::UModDeployerSaveGame()
{
#if PLATFORM_LINUX
	PaksFolder = "~/.local/share/Steam/steamapps/compatdata/361420/pfx/drive_c/users/steamuser/AppData/Local/Astro/Saved/Paks";
	InstallationPaksFolder = "~/.local/share/Steam/steamapps/common/ASTRONEER/Astro/Content/Paks";
#endif
}
