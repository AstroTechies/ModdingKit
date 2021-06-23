// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/AstroStatics.h"
#include "Items/ItemType.h"
#include "AstroMissionData.generated.h"

UENUM(BlueprintType)
enum class EAstroMissionObjectiveType : uint8 {
	HarvestResource = 0,
	PrintItem = 1,
	SlotItem = 2,
	CreateItem = 3,
	PowerItem = 4,
	FullyChargeItem = 5,
	FillItem = 6,
	PlanetFall = 7,
	FindGateChamber = 8,
	ActivateGateChamber = 9,
	FindGateEngine = 10,
	ActivateGateEngine = 11,
	Custom = 12,
	ConnectToPower = 13,
	SlottedByAutoArm = 14,
	ItemPlaced = 15,
	PuzzleSolved = 16,
	CatalogUnlock = 17,
	BytesReached = 18,
	ResearchCompleted = 19,
	ItemUsed = 20,
	ItemExists = 21,
	ConnectToOxygen = 22,
	SlotInDeformTool = 23,
	ExplodeItem = 24,
	DrainItem = 25,
	ConsumeItem = 26,
	ItemPickedUp = 27,
	None = 28
};

USTRUCT(BlueprintType)
struct ASTRO_API FAstroMissionObjectiveProgress
{
	GENERATED_USTRUCT_BODY();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FText Description;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TArray<TSubclassOf<UItemType>> TargetType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TArray<TSubclassOf<UItemType>> SecondaryTargetType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FString CustomTag;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float Goal;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float Progress;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float LastNotifiedProgressValue;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float ProgressNotifyThreshold;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) EPlanetIdentifier Planet;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) EAstroMissionObjectiveType ObjectiveType;
};

USTRUCT(BlueprintType)
struct ASTRO_API FAstroMissionObjective
{
	GENERATED_USTRUCT_BODY();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FText Description;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TArray<TSubclassOf<UItemType>> TargetType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TArray<TSubclassOf<UItemType>> SecondaryTargetType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FString CustomTag;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float Value;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float StartingValue;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float ProgressNotifyThreshold;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) EPlanetIdentifier Planet;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) EAstroMissionObjectiveType ObjectiveType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) bool bIsOverrideObjective;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) bool bIsPlanetExclude;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) bool bIsHiddenObjective;
};

USTRUCT(BlueprintType)
struct ASTRO_API FAstroMissionData
{
	GENERATED_USTRUCT_BODY();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FName MissionId;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FName MissionCatagory;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TArray<FAstroMissionObjective> Objectives;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FText Title;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FText Decription;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) EAstroColor NotificationColor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UTexture2D* NotificationIcon; // This is technically UObject*, but for our purposes UTexture2D* works fine
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TArray<FName> NextMissions;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TMap<TSubclassOf<UItemType>,int> Rewards;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TArray<TSubclassOf<UItemType>> ResearchRewards;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TArray<FString> PlayFabRewards;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) int MissionLogPriority;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) int ByteRewardValue;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) bool bAutoActivate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) bool bAutoCompleteOnExistingGames;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) bool bSuppressActivationNotification;
};

USTRUCT(BlueprintType)
struct ASTRO_API FAstroMissionState
{
	GENERATED_USTRUCT_BODY();

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite) FName MissionId;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) int MissionLogPriority;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TArray<FAstroMissionObjectiveProgress> ObjectiveProgressList;
};

UCLASS(BlueprintType)
class ASTRO_API UAstroMissionDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TArray<FAstroMissionData> MissionsData;
};