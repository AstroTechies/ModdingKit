#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "CurrentlySelectedItemChangedDelegate.generated.h"

class UItemType;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCurrentlySelectedItemChanged, TSubclassOf<UItemType>, SelectedItem);

