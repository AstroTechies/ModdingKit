#pragma once
#include "CoreMinimal.h"
#include "EItemVariantType.h"
#include "OnItemIconMeshClickedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnItemIconMeshClicked, int32, ItemTypeVariantIndex, EItemVariantType, ItemVariantType);

