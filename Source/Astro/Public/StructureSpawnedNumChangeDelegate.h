#pragma once
#include "CoreMinimal.h"
#include "EMegastructureType.h"
#include "StructureSpawnedNumChangeDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FStructureSpawnedNumChange, int32, megastructureNumber, EMegastructureType, megastructureType);

