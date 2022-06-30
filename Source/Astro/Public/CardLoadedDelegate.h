#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "EAstroGameMenuTutoriaSlideCardKey.h"
#include "CardLoadedDelegate.generated.h"

class UUserWidget;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FCardLoaded, EAstroGameMenuTutoriaSlideCardKey, Key, TSubclassOf<UUserWidget>, Widget);

