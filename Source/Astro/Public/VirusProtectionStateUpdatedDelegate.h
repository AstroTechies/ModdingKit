#pragma once
#include "CoreMinimal.h"
#include "EPlanetIdentifier.h"
#include "VirusProtectionStateUpdatedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FVirusProtectionStateUpdated, EPlanetIdentifier, planetID);

