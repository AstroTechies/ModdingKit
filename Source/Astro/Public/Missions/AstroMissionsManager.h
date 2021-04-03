// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Items/ItemType.h"
#include "Missions/AstroMissionData.h"
#include "Utilities/ActivationSignals.h"
#include "AstroMissionsManager.generated.h"

UCLASS()
class ASTRO_API AAstroMissionsManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAstroMissionsManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, BlueprintPure) bool GetMissionDataBP(FName missionId, FAstroMissionData& outMissionData);
	UFUNCTION(BlueprintCallable, BlueprintPure) bool GetMissionStateBP(FName missionId, FAstroMissionState& outMissionState);
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly) void AuthorityRaiseMissionEvent(EAstroMissionObjectiveType objectiveType, TSubclassOf<UItemType> targetType, TSubclassOf<UItemType> secondaryTargetType, const float count, EPlanetIdentifier planet, FString CustomTag);

	UPROPERTY(EditAnywhere, BlueprintReadWrite) TMap<FName, FAstroMissionData> AllMissions;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TArray<FAstroMissionState> CompletedMissions;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TArray<FAstroMissionState> ActiveMissions;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TArray<FString> CompletedCustomTags;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FSignal OnMissionsInitialized;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FAstroMissionActivatedDelegate OnMissionActivated;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FAstroMissionObjectiveUpdatedDelegate OnMissionObjectiveUpdated;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FAstroMissionCompletedDelegate OnMissionCompleted;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FAstroMissionRewardClaimedDelegate OnMissionRewardClaimed;
};
