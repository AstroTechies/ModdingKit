#pragma once
#include "CoreMinimal.h"
#include "EItemConverterState.h"
#include "OnItemConverterStateChangedDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnItemConverterStateChanged, EItemConverterState, NewState, EItemConverterState, prevState);

