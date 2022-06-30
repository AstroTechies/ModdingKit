#pragma once
#include "CoreMinimal.h"
#include "AstroEntityComponent.h"
#include "AstroDatumRef.h"
#include "StreamingPowerMergedConnectionComponent.generated.h"

USTRUCT(BlueprintType)
struct FStreamingPowerMergedConnectionComponent : public FAstroEntityComponent {
    GENERATED_BODY()
public:
    UPROPERTY(SaveGame)
    FAstroDatumRef FromNode;
    
    UPROPERTY(SaveGame)
    FAstroDatumRef ToNode;
    
    ASTRO_API FStreamingPowerMergedConnectionComponent();
};

