#pragma once
#include "CoreMinimal.h"
#include "JoinFriendSessionCompleteDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FJoinFriendSessionComplete, bool, Status);

