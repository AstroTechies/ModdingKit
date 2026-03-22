#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "OnItemTypeListChangedDelegate.generated.h"

class UItemType;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnItemTypeListChanged, const TArray<TSubclassOf<UItemType>>&, UpdatedItemTypeList);

