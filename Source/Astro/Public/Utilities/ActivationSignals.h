// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/ItemType.h"
#include "Missions/AstroMissionData.h"
#include "UObject/NoExportTypes.h"
#include "ActivationSignals.generated.h"

class APhysicalItem;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSignal);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSlotReleased, bool, Unknown);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FItemDropInWorldDelegate, UPrimitiveComponent*, Component, FVector, Point, FVector, Normal);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FItemDropInWorldTerrainDelegate, UPrimitiveComponent*, Component, FVector, Point, FVector, Normal, bool, Unknown4);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPickedUp, bool, Unknown);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMoved, bool, Unknown);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnReplicationDataChanged, APhysicalItem*, Unknown);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGameplayStarted, bool, StartedInExistingSavedGame);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FTutorialSignal, FName, Unknown1, bool, Unknown2, bool, Unknown3);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FStarterItemCreated, APhysicalItem*, NewStarterItem);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCurrentResearchPointBalanceChanged, float, NewPointBalance);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnItemTypeListChanged, TArray<TSubclassOf<UItemType>>, NewItemTypeList);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEnableSignal, bool, Unknown);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPlayerJoinSignal, APlayerController*, Player);

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE(FFailedToSaveGameOnQuit);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSlotEventSignal, APhysicalItem *, Unknown0);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEnterExitSignal, bool, Unknown0);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FItemPrintedSignal, APhysicalItem*, PrintedItem);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCrackedStateChanged, UCrackableActorComponent *, Unknown0, bool, Unknown1);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAstroMissionActivatedDelegate, FName, missionId);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FAstroMissionObjectiveUpdatedDelegate, FName, missionId, FAstroMissionObjectiveProgress, objectiveProgress, int, objectiveIndex);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAstroMissionCompletedDelegate, FName, missionId);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAstroMissionRewardClaimedDelegate, FName, missionId);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FIsBuriedChangedEvent, UTerrainPhysicsComponent *, TargetComponent);