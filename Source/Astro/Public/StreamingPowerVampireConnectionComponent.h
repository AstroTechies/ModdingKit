#pragma once
#include "CoreMinimal.h"
#include "AstroEntityComponent.h"
#include "AstroDatumRef.h"
#include "StreamingPowerVampireConnectionComponent.generated.h"

USTRUCT(BlueprintType)
struct FStreamingPowerVampireConnectionComponent : public FAstroEntityComponent {
    GENERATED_BODY()
public:
    UPROPERTY(SaveGame)
    FAstroDatumRef VampireNode;
    
    UPROPERTY(SaveGame)
    FAstroDatumRef PreyNode;
    
    ASTRO_API FStreamingPowerVampireConnectionComponent();
};

