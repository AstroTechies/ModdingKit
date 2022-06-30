#pragma once
#include "CoreMinimal.h"
#include "AstroEntityComponent.h"
#include "AstroDatumRef.h"
#include "StreamingPowerCableComponent.generated.h"

USTRUCT(BlueprintType)
struct FStreamingPowerCableComponent : public FAstroEntityComponent {
    GENERATED_BODY()
public:
    UPROPERTY(SaveGame)
    FAstroDatumRef FromNode;
    
    UPROPERTY(SaveGame)
    FAstroDatumRef ToNode;
    
    UPROPERTY(SaveGame)
    FAstroDatumRef StreamingPowerDirectionalConnection;
    
    UPROPERTY(SaveGame)
    FAstroDatumRef StreamingPowerMergedConnection;
    
    ASTRO_API FStreamingPowerCableComponent();
};

