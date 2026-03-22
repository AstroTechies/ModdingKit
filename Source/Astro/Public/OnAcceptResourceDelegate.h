#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "OnAcceptResourceDelegate.generated.h"

class UItemType;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAcceptResource, TSubclassOf<UItemType>, Type, int32, Amount);

