#pragma once
#include "CoreMinimal.h"
#include "AstroEntityComponent.h"
#include "AstroDatumRef.h"
#include "StreamingPowerMergedNodeComponent.generated.h"

USTRUCT(BlueprintType)
struct FStreamingPowerMergedNodeComponent : public FAstroEntityComponent {
    GENERATED_BODY()
public:
    UPROPERTY(SaveGame)
    TArray<FAstroDatumRef> ChildNodes;
    
    ASTRO_API FStreamingPowerMergedNodeComponent();
};

