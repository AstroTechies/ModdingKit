#pragma once
#include "CoreMinimal.h"
#include "EEmoteType.h"
#include "PlayerEmoteSignalDelegate.generated.h"

class APlayController;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FPlayerEmoteSignal, EEmoteType, EmoteType, APlayController*, Player);

