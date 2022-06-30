#pragma once
#include "CoreMinimal.h"
#include "StarterItemCreatedDelegate.generated.h"

class APhysicalItem;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FStarterItemCreated, APhysicalItem*, StarterItem);

