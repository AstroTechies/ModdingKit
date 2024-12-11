#pragma once
#include "CoreMinimal.h"
#include "EPlanetIdentifier.h"
#include "FirewallStateUpdatedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FFirewallStateUpdated, EPlanetIdentifier, planetID, int32, submittedCounterhackKeyCount);

