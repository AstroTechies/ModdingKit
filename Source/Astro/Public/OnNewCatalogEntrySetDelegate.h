#pragma once
#include "CoreMinimal.h"
#include "OnNewCatalogEntrySetDelegate.generated.h"

class UItemCatalogEntrySpindleDisplay;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnNewCatalogEntrySet, UItemCatalogEntrySpindleDisplay*, Display);

