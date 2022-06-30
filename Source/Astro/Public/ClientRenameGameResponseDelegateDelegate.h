#pragma once
#include "CoreMinimal.h"
#include "ClientRenameGameResponseDelegateDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FClientRenameGameResponseDelegate, bool, copySuccess, bool, removeSuccess, const FString&, fromName, const FString&, twoName);

