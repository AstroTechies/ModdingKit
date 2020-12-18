// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CheatManager.h"
#include "AstroCheatManager.generated.h"

/**
 * 
 */
UCLASS()
class ASTRO_API UAstroCheatManager : public UCheatManager
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
		void AstroGrantResearchPoints(int numResearchPoints);
	UFUNCTION(BlueprintCallable)
		void AstroResetResearchPoints();
	UFUNCTION(BlueprintCallable)
		void AstroResetResearchUnlocks();
	UFUNCTION(BlueprintCallable)
		void AstroResetNumTimesCreativeTutorialShown();
	UFUNCTION(BlueprintCallable)
		void AstroRevealGateStation();
	UFUNCTION(BlueprintCallable)
		void AstroPlayOutroCinematic();
	UFUNCTION(BlueprintCallable)
		void AstroAllProbesSpawnWandererRealityTear(bool bAlwaysSpawn);
	UFUNCTION(BlueprintCallable)
		void AstroResetEarnedItemDrivePhysicalRewards();
	UFUNCTION(BlueprintCallable)
		void AstroToggleWorldUI();
	UFUNCTION(BlueprintCallable)
		void AstroToggle2DUI();
	UFUNCTION(BlueprintCallable)
		void AstroToggleHUD();
	UFUNCTION(BlueprintCallable)
		void ToggleStreamingPowerDebugVis();
	UFUNCTION(BlueprintCallable)
		void ToggleSelectionOutline();
	UFUNCTION(BlueprintCallable)
		void ToggleDrillUI();
	UFUNCTION(BlueprintCallable)
		void AstroFindVintageProbe();
	UFUNCTION(BlueprintCallable)
		void AstroDebugFakeDeadlockAndCrash();
	UFUNCTION(BlueprintCallable)
		void AstroDebugDisableMultiplayer();
	UFUNCTION(BlueprintCallable, Server, Reliable, WithValidation)
		void ServerGrantResearchPoints(int numResearchPoints);
	UFUNCTION(BlueprintCallable, Server, Reliable, WithValidation)
		void ServerResetResearchPoints();
	UFUNCTION(BlueprintCallable, Server, Reliable, WithValidation)
		void ServerResetResearchUnlocks();
	UFUNCTION(BlueprintCallable, Server, Reliable, WithValidation)
		void ServerRevealGateStation();
	UFUNCTION(BlueprintCallable, Server, Reliable, WithValidation)
		void ServerPlayOutroCinematic();
};
