#pragma once
#include "CoreMinimal.h"
#include "ItemPrintedSignalDelegate.generated.h"

class APhysicalItem;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FItemPrintedSignal, APhysicalItem*, Item);

