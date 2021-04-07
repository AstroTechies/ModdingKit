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
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly) void AuthorityActivateMission(FName missionId);
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly) void AuthorityCompleteMission(FName missionId);

	UPROPERTY(EditAnywhere, BlueprintReadWrite) TMap<FName, FAstroMissionData> AllMissions;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TArray<FAstroMissionState> CompletedMissions;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TArray<FAstroMissionState> ActiveMissions;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TArray<FString> CompletedCustomTags;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintAssignable) FSignal OnMissionsInitialized;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintAssignable) FAstroMissionActivatedDelegate OnMissionActivated;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintAssignable) FAstroMissionObjectiveUpdatedDelegate OnMissionObjectiveUpdated;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintAssignable) FAstroMissionCompletedDelegate OnMissionCompleted;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintAssignable) FAstroMissionRewardClaimedDelegate OnMissionRewardClaimed;
};
