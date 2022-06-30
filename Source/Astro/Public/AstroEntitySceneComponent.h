#pragma once
#include "CoreMinimal.h"
#include "AstroEntityComponent.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Transform2 -FallbackName=Transform2
#include "AstroEntitySceneComponent.generated.h"

USTRUCT(BlueprintType)
struct FAstroEntitySceneComponent : public FAstroEntityComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, SaveGame, meta=(AllowPrivateAccess=true))
    FTransform WorldTransform;
    
    ASTRO_API FAstroEntitySceneComponent();
};

