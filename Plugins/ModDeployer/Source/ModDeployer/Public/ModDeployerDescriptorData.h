#pragma once

#include "CoreMinimal.h"
#include "ModDeployerDescriptorData.generated.h"

class FModDeployerModule;

UENUM()
enum class EModDeployerPlatformType : uint8
{
	Steam = 0,
	MicrosoftStore = 1,
	Other = 2
};

UCLASS()
class UModDeployerDescriptorData : public UObject
{
	GENERATED_BODY()

public:

	UModDeployerDescriptorData(const FObjectInitializer& ObjectInitializer);

	// Your mod ID
	UPROPERTY(EditAnywhere, SaveGame, Category = "Deployment Information", meta = (DisplayName = "Mod ID"))
	FString ModID = "TestMod";

	// Your mod version
	UPROPERTY(EditAnywhere, SaveGame, Category = "Deployment Information", meta = (DisplayName = "Mod Version"))
	FString ModVersion = "0.1.0";

	// The path to the folder (or single file) where your mod assets are. You can add multiple folders by adding multiple lines
	UPROPERTY(EditAnywhere, SaveGame, Category = "Deployment Information", meta = (DisplayName = "Mod Folder", MultiLine = true))
	FString ModFolder = "Astro/Content/Mods/YourNameHere/TestMod";

	// The path to the folder where the game loads .pak files
	UPROPERTY(EditAnywhere, SaveGame, Category = "Deployment Information", meta = (DisplayName = "Output Paks Folder"))
	FString PaksFolder = "%LOCALAPPDATA%\\Astro\\Saved\\Paks";

	// The path to the folder where the base game's .pak files are located
	UPROPERTY(EditAnywhere, SaveGame, Category = "Deployment Information", meta = (DisplayName = "Installation Paks Folder"))
	FString InstallationPaksFolder = "D:\\Games\\steamapps\\common\\ASTRONEER\\Astro\\Content\\Paks";

	UPROPERTY(EditAnywhere, SaveGame, Category = "Deployment Information", meta = (DisplayName = "Platform (for Launch)"))
	EModDeployerPlatformType Platform = EModDeployerPlatformType::Steam;

	// The full text of your metadata.json file; see astroneermodding.readthedocs.io for more info
	UPROPERTY(EditAnywhere, SaveGame, Category = "Metadata", meta = (DisplayName = "metadata.json", MultiLine = true))
	FString metadata = "{\n    \"schema_version\": 2,\n    \"name\": \"Test Mod\",\n    \"mod_id\": \"TestMod\",\n    \"author\": \"You\",\n    \"description\": \"My test mod\",\n    \"version\": \"0.1.0\",\n    \"sync\": \"serverclient\",\n    \"homepage\": \"https://example.com\",\n    \"integrator\": {\n        \n    }\n}";


};