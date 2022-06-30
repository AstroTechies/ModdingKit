#pragma once
#include "CoreMinimal.h"
#include "JoinFriendSessionCompleteDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FJoinFriendSessionComplete, bool, Status);

