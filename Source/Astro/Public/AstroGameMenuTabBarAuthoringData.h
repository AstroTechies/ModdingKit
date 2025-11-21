#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "AstroGameMenuTabBarAuthoringData.generated.h"

class UAstroGameMenuSubPaneWidget;
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
    TSubclassOf<UAstroGameMenuTabBarButtonWidget> DefaultTabClassLeft;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAstroGameMenuSubPaneWidget> DefaultSubPaneLeft;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAstroGameMenuSubPaneWidget> DefaultSubPaneRight;
    
    ASTRO_API FAstroGameMenuTabBarAuthoringData();
};

