#pragma once
#include "CoreMinimal.h"
#include "UserWidgetSignalDelegate.generated.h"

class UUserWidget;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FUserWidgetSignal, UUserWidget*, Widget);

