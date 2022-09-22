#pragma once
#include "CoreMinimal.h"
#include "ETileInputIndex.h"
#include "Blueprint/UserWidget.h"
#include "TileInputSignalDelegate.generated.h"

class UUserWidget;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTileInputSignal, UUserWidget*, Widget, TEnumAsByte<ETileInputIndex>, InputIndex);

