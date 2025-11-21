#pragma once
#include "CoreMinimal.h"
#include "AstroGameMenuTabBarAuthoringData.h"
#include "Templates/SubclassOf.h"
#include "AstroGameMenuNavigationCoordinates.generated.h"

class UAstroGameMenuSubPaneWidget;

USTRUCT(BlueprintType)
struct FAstroGameMenuNavigationCoordinates {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAstroGameMenuTabBarAuthoringData TabBarAuthoringData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 TabBarSelectionIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAstroGameMenuSubPaneWidget> SubPaneLeft;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAstroGameMenuSubPaneWidget> SubPaneRight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SubPaneItemSelectionIndex;
    
    ASTRO_API FAstroGameMenuNavigationCoordinates();
};

