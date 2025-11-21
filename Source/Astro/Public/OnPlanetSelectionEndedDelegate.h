#pragma once
#include "CoreMinimal.h"
#include "OnPlanetSelectionEndedDelegate.generated.h"

class ASolarBody;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPlanetSelectionEnded, ASolarBody*, Body);

