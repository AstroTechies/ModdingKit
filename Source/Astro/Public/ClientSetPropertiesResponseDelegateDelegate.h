#pragma once
#include "CoreMinimal.h"
#include "AstroClientProperties.h"
#include "ClientSetPropertiesResponseDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FClientSetPropertiesResponseDelegate, const FAstroClientProperties&, clientCapabilities);

