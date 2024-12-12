#pragma once
#include "CoreMinimal.h"
#include "ETileInputIndex.h"
#include "TileInputSignalDelegate.generated.h"

class UUserWidget;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTileInputSignal, UUserWidget*, Widget, TEnumAsByte<ETileInputIndex>, InputIndex);

