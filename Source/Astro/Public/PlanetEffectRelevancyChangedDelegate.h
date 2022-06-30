#pragma once
#include "CoreMinimal.h"
#include "PlanetEffectRelevancyChangedDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPlanetEffectRelevancyChanged, bool, NewIsInRelevancy);

