#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "OnLandedOnGroundDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLandedOnGround, TEnumAsByte<EPhysicalSurface>, GroundSurface);

