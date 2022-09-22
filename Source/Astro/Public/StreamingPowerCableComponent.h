#pragma once
#include "CoreMinimal.h"
#include "AstroEntityComponent.h"
#include "AstroDatumRef.h"
#include "StreamingPowerCableComponent.generated.h"

USTRUCT(BlueprintType)
struct FStreamingPowerCableComponent : public FAstroEntityComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FAstroDatumRef FromNode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FAstroDatumRef ToNode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FAstroDatumRef StreamingPowerDirectionalConnection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FAstroDatumRef StreamingPowerMergedConnection;
    
    ASTRO_API FStreamingPowerCableComponent();
};

