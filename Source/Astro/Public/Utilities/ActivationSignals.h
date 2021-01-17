// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/ItemType.h"
#include "UObject/NoExportTypes.h"
#include "ActivationSignals.generated.h"

class APhysicalItem;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSignal);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSlotReleased, bool, Unknown);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FItemDropInWorldDelegate, UPrimitiveComponent*, Unknown1, FVector, Unknown2, FVector, Unknown3);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FItemDropInWorldTerrainDelegate, UPrimitiveComponent*, Unknown1, FVector, Unknown2, FVector, Unknown3, bool, Unknown4);

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