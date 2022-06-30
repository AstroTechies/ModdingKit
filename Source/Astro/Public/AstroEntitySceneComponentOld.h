#pragma once
#include "CoreMinimal.h"
#include "AstroEntityComponent.h"
#include "UObject/NoExportTypes.h"
#include "AstroEntitySceneComponentOld.generated.h"

USTRUCT(BlueprintType)
struct FAstroEntitySceneComponentOld : public FAstroEntityComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, SaveGame, meta=(AllowPrivateAccess=true))
    FTransform WorldTransform;
    
    ASTRO_API FAstroEntitySceneComponentOld();
};

