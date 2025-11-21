#pragma once
#include "CoreMinimal.h"
#include "ParticleStateChangedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FParticleStateChanged, bool, NewState);

