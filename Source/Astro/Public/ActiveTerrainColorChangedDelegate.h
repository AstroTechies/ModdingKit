#pragma once
#include "CoreMinimal.h"
#include "ActiveTerrainColorChangedDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FActiveTerrainColorChanged, bool, PickedWithEyedropperTool);

