#pragma once
#include "CoreMinimal.h"
#include "OnActiveCatalogEntryChangedDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnActiveCatalogEntryChanged, bool, bImmediate);

