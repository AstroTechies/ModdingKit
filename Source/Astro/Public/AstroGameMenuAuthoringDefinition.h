#pragma once
#include "CoreMinimal.h"
#include "AstroGameMenuTabBarAuthoringData.h"
#include "AstroGameMenuAuthoringDefinition.generated.h"

USTRUCT(BlueprintType)
struct FAstroGameMenuAuthoringDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAstroGameMenuTabBarAuthoringData TabBarAuthoringData;
    
    ASTRO_API FAstroGameMenuAuthoringDefinition();
};

