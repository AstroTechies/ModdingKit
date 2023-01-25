#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Transform -FallbackName=Transform
#include "AstroEntityComponent.h"
#include "AstroEntitySceneComponentOld.generated.h"

USTRUCT(BlueprintType)
struct FAstroEntitySceneComponentOld : public FAstroEntityComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FTransform WorldTransform;
    
    ASTRO_API FAstroEntitySceneComponentOld();
};

