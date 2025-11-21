#pragma once
#include "CoreMinimal.h"
#include "EPlanetIdentifier.h"
#include "OnBeginTransitionSequenceDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnBeginTransitionSequence, EPlanetIdentifier, inPlanetToMoveTo);

