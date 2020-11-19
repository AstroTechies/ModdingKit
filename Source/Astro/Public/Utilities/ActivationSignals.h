// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ActivationSignals.generated.h"

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