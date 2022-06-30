#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "OnItemConversionCompleteDelegate.generated.h"

class UItemType;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnItemConversionComplete, const TArray<TSubclassOf<UItemType>>&, outputItemTypes);

