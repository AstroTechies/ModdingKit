#pragma once
#include "CoreMinimal.h"
#include "PlayerList.h"
#include "ClientListPlayersResponseDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FClientListPlayersResponseDelegate, const FPlayerList&, PlayerList);

