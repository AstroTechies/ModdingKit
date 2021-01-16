// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Engine/LocalPlayer.h"
#include "AstroStatics.generated.h"

class UPanelWidget;

UENUM(BlueprintType)
enum class EPlatform : uint8 {
	PC = 0,
	UniversalWindows = 1,
	XboxOne = 2,
	PS4 = 3
};

UCLASS()
class ASTRO_API UAstroStatics : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (WorldContext = "WorldContextObject"))
		static AAstroGameMode* GetGameMode(UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (WorldContext = "WorldContextObject"))
		static AAstroGameState* GetGameState(UObject* WorldContextObject);

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
