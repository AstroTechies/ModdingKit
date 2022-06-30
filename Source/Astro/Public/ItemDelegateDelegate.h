#pragma once
#include "CoreMinimal.h"
#include "ItemDelegateDelegate.generated.h"

class APhysicalItem;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FItemDelegate, APhysicalItem*, Item);

