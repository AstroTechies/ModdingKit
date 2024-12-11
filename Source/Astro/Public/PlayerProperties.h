#pragma once
#include "CoreMinimal.h"
#include "EPlayerCategory.h"
#include "PlayerProperties.generated.h"

USTRUCT(BlueprintType)
struct FPlayerProperties {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString PlayerFirstJoinName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPlayerCategory PlayerCategory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString PlayerGuid;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString PlayerRecentJoinName;
    
    ASTRO_API FPlayerProperties();
};

