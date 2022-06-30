#pragma once
#include "CoreMinimal.h"
#include "StreamingPowerPacket.h"
#include "AstroEntityComponent.h"
#include "AstroDatumRef.h"
#include "StreamingPowerDirectionalConnectionComponent.generated.h"

USTRUCT(BlueprintType)
struct FStreamingPowerDirectionalConnectionComponent : public FAstroEntityComponent {
    GENERATED_BODY()
public:
    UPROPERTY(Transient, VisibleInstanceOnly)
    TMap<int32, FStreamingPowerPacket> PowerPacketsOnTheLine;
    
    UPROPERTY(SaveGame)
    FAstroDatumRef FromNode;
    
    UPROPERTY(SaveGame)
    FAstroDatumRef ToNode;
    
    UPROPERTY(SaveGame)
    float OverrideSplitRatio;
    
    UPROPERTY(SaveGame)
    uint8 bFlowInterrupted: 1;
    
    ASTRO_API FStreamingPowerDirectionalConnectionComponent();
};

