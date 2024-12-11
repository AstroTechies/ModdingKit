#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "OnMoveDelegate.generated.h"

class APlayerController;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMove, APlayerController*, Controller, const FVector&, Direction);

