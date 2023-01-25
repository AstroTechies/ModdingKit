#pragma once
#include "CoreMinimal.h"
#include "AstroDatumRef.h"
#include "AstroEntityComponent.h"
#include "StreamingPowerMergedConnectionComponent.generated.h"

USTRUCT(BlueprintType)
struct FStreamingPowerMergedConnectionComponent : public FAstroEntityComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FAstroDatumRef FromNode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FAstroDatumRef ToNode;
    
    ASTRO_API FStreamingPowerMergedConnectionComponent();
};

