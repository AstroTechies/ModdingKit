#pragma once
#include "CoreMinimal.h"
#include "PlayerJoinSignalDelegate.generated.h"

class APlayerController;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPlayerJoinSignal, APlayerController*, NewPlayer);

