#pragma once
#include "CoreMinimal.h"
#include "OnJoinedAsClientDelegate.generated.h"

class AAstroPlayerController;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnJoinedAsClient, AAstroPlayerController*, Controller);

