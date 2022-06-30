#pragma once
#include "CoreMinimal.h"
#include "PlayerJoinSignalDelegate.generated.h"

class APlayerController;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPlayerJoinSignal, APlayerController*, NewPlayer);

