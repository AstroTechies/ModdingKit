#pragma once
#include "CoreMinimal.h"
#include "AttachedActorSignalDelegate.generated.h"

class AActor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAttachedActorSignal, AActor*, attachedActor);

