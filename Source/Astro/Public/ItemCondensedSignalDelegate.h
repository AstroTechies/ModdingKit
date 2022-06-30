#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "ItemCondensedSignalDelegate.generated.h"

class AAtmosphericCondenserBase;
class UItemType;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FItemCondensedSignal, AAtmosphericCondenserBase*, CondenserRef, TSubclassOf<UItemType>, CondensedResource, int32, AmountCondensed);

