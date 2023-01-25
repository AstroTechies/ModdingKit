#pragma once
#include "CoreMinimal.h"
#include "ActorClickSignalDelegate.generated.h"

class AActor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FActorClickSignal, AActor*, Actor);

