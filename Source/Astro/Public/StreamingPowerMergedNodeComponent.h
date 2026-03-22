#pragma once
#include "CoreMinimal.h"
#include "AstroDatumRef.h"
#include "AstroEntityComponent.h"
#include "StreamingPowerMergedNodeComponent.generated.h"

USTRUCT(BlueprintType)
struct FStreamingPowerMergedNodeComponent : public FAstroEntityComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FAstroDatumRef> ChildNodes;
    
    ASTRO_API FStreamingPowerMergedNodeComponent();
};

