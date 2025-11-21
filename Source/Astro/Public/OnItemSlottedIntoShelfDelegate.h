#pragma once
#include "CoreMinimal.h"
#include "OnItemSlottedIntoShelfDelegate.generated.h"

class ADisplayCaseShelf;
class APhysicalItem;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnItemSlottedIntoShelf, APhysicalItem*, inItem, ADisplayCaseShelf*, thisItem);

