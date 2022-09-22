#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "OnResourceStoredDelegate.generated.h"

class UItemType;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnResourceStored, TSubclassOf<UItemType>, Type);