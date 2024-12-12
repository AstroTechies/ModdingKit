#pragma once
#include "CoreMinimal.h"
#include "ClickResult.h"
#include "ToolDoClickSignalDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FToolDoClickSignal, const FClickResult&, Click);

