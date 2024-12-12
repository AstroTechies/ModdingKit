#pragma once
#include "CoreMinimal.h"
#include "OnCrackedStateChangedDelegate.generated.h"

class UCrackableActorComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCrackedStateChanged, UCrackableActorComponent*, CrackableActorComponent, bool, bIsCracked);

