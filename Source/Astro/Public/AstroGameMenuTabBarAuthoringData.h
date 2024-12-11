#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "AstroGameMenuTabBarAuthoringData.generated.h"

class UAstroGameMenuTabBarButtonWidget;

USTRUCT(BlueprintType)
struct FAstroGameMenuTabBarAuthoringData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UAstroGameMenuTabBarButtonWidget>> LeftTabBarGroupButtons;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UAstroGameMenuTabBarButtonWidget>> RightTabBarGroupButtons;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAstroGameMenuTabBarButtonWidget> DefaultTabClass;
    
    ASTRO_API FAstroGameMenuTabBarAuthoringData();
};

