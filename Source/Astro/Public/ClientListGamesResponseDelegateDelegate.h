#pragma once
#include "CoreMinimal.h"
#include "GameList.h"
#include "ClientListGamesResponseDelegateDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FClientListGamesResponseDelegate, const FGameList&, GameList);

