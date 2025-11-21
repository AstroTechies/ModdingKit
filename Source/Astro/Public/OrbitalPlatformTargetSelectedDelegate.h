#pragma once
#include "CoreMinimal.h"
#include "EPlanetIdentifier.h"
#include "OrbitalPlatformTargetSelectedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOrbitalPlatformTargetSelected, EPlanetIdentifier, planetID);

