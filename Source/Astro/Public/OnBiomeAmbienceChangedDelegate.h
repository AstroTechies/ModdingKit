#pragma once
#include "CoreMinimal.h"
#include "OnBiomeAmbienceChangedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnBiomeAmbienceChanged, const FString&, AmbientSoundEvent);

