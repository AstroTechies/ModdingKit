#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "OnCollectionUpdatedDelegate.generated.h"

class UItemType;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCollectionUpdated, TArray<TSubclassOf<UItemType>>, inItemArray);

