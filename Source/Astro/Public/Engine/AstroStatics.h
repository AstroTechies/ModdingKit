// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Engine/LocalPlayer.h"
#include "AstroStatics.generated.h"

class UPanelWidget;
class AAstroMissionsManager;

UENUM(BlueprintType)
enum class EPlatform : uint8 {
	PC = 0,
	UniversalWindows = 1,
	XboxOne = 2,
	PS4 = 3
};

UENUM(BlueprintType)
enum class EAstroColor : uint8 {
	None = 0,
	Clear = 1,
	NullColor = 2,
	AstroBlue = 3,
	PolarWhite = 4,
	HazyWhite = 5,
	CharcoalGray = 6,
	AsphaltGray = 7,
	TitaniumGray = 8,
	SilverGray = 9,
	GoldenYellow = 10,
	AlertRed = 11,
	GoGreen = 12,
	ExoticPurple = 13,
	SafetyOrange = 14,
	OxygenBlue = 15,
	LapisBlue = 16,
	AtmoTeal = 17,
	HydroBlue = 18,
	CeruleanBlue = 19,
	JeweledPink = 20
};

UENUM(BlueprintType)
enum class EPlanetIdentifier : uint8 {
	None = 0,
	Terran = 1 UMETA(DisplayName = "Sylva"),
	TerranMoon = 2 UMETA(DisplayName = "Desolo"),
	Exotic = 3 UMETA(DisplayName = "Vesania"),
	ExoticMoon = 4 UMETA(DisplayName = "Novus"),
	Arid = 5 UMETA(DisplayName = "Calidor"),
	Tundra = 6 UMETA(DisplayName = "Glacio"),
	Radiated = 7 UMETA(DisplayName = "Atrox")
};

UCLASS()
class ASTRO_API UAstroStatics : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (WorldContext = "WorldContextObject"))
		static AAstroGameMode* GetGameMode(UObject* WorldContextObject);
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (WorldContext = "WorldContextObject"))
		static AAstroGameState* GetGameState(UObject* WorldContextObject);
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (WorldContext = "WorldContextObject"))
		static UAstroGameInstance* GetGameInstance(UObject* WorldContextObject);
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (WorldContext = "WorldContextObject"))
		static AAstroMissionsManager* GetAstroMissionsManager(UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
		static void JoinToURL(UPARAM(ref) FString& Name, UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, BlueprintPure)
		static FString GetControllingPlayerNickname();
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool IsPlatformGameConsole();
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool IsPlatformPS4();
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool IsPlatformUWPOrXbox();
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool IsDedicatedServerUIEnabled();
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (WorldContext = "WorldContextObject"))
		static bool IsDedicatedServer(UObject* WorldContextObject);
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (WorldContext = "WorldContextObject"))
		static bool IsConnectedToDedicatedServer(UObject* WorldContextObject);
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (WorldContext = "WorldContextObject"))
		static bool IsLanMatch(UObject* WorldContextObject);
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static bool IsShippingBuild();

	UFUNCTION(BlueprintCallable)
		static void PopulateLoadablePresets(UPanelWidget* widget);
	UFUNCTION(BlueprintCallable)
		static void PopulateSpawnableObjects(UPanelWidget* widget, FString nameFilter);
	UFUNCTION(BlueprintCallable)
		static void PopulateResourceTypes(UPanelWidget* widget);
	UFUNCTION(BlueprintCallable)
		static void PopulateSaveGames(UPanelWidget* widget);

	//UFUNCTION(BlueprintCallable, BlueprintPure)
		static EPlatform GetGamePlatform(); // doesn't seem to actually do what it says

	UFUNCTION(BlueprintCallable)
		static void ThisMethodDoesNotExist();
};
