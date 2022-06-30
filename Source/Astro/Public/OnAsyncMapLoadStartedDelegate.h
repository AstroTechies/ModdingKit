#pragma once
#include "CoreMinimal.h"
#include "OnAsyncMapLoadStartedDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAsyncMapLoadStarted, const FString&, Map);

