#pragma once
#include "CoreMinimal.h"
#include "ActorProximityDelegateDelegate.generated.h"

class AActor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FActorProximityDelegate, AActor*, ActorInProximity);

