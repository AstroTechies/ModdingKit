#pragma once
#include "CoreMinimal.h"
#include "EAstroGameMenuTutoriaSlideCardKey.h"
#include "Templates/SubclassOf.h"
#include "CardLoadedDelegate.generated.h"

class UUserWidget;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FCardLoaded, EAstroGameMenuTutoriaSlideCardKey, Key, TSubclassOf<UUserWidget>, Widget);

