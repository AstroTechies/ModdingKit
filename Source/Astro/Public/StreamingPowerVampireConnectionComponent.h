#pragma once
#include "CoreMinimal.h"
#include "AstroEntityComponent.h"
#include "AstroDatumRef.h"
#include "StreamingPowerVampireConnectionComponent.generated.h"

USTRUCT(BlueprintType)
struct FStreamingPowerVampireConnectionComponent : public FAstroEntityComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FAstroDatumRef VampireNode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FAstroDatumRef PreyNode;
    
    ASTRO_API FStreamingPowerVampireConnectionComponent();
};

