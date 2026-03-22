#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "OnItemTypeChangedDelegate.generated.h"

class UItemComponent;
class UItemType;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnItemTypeChanged, UItemComponent*, ItemComponent, TSubclassOf<UItemType>, NewItemType);

