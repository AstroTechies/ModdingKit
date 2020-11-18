// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Engine/LocalPlayer.h"
#include "AstroStatics.generated.h"

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

	//UFUNCTION(BlueprintCallable, BlueprintPure)
		static EPlatform GetGamePlatform(); // Doesn't seem to actually work

	//UFUNCTION(BlueprintCallable, BlueprintPure)
		static uint64 GetGuidForController(APlayerController* controller); // Not callable with the regular engine
	
	
};
