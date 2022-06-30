#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "OnSampledTerrainMaterialChangedDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSampledTerrainMaterialChanged, float, NewHardness, FLinearColor, NewColor);

