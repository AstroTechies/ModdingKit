#pragma once
#include "CoreMinimal.h"
#include "OnTileFocusPathChangeDelegate.generated.h"

class UUserWidget;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTileFocusPathChange, UUserWidget*, Widget);

