#pragma once
#include "CoreMinimal.h"
#include "AstroGameMenuDedicatedServerDisplayData.generated.h"

USTRUCT(BlueprintType)
struct FAstroGameMenuDedicatedServerDisplayData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText ServerName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 NumPlayers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ServerCapacity;
    
    ASTRO_API FAstroGameMenuDedicatedServerDisplayData();
};

