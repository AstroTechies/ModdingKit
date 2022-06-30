#pragma once
#include "CoreMinimal.h"
#include "EPlayerCategory.h"
#include "PlayerProperties.generated.h"

USTRUCT(BlueprintType)
struct FPlayerProperties {
    GENERATED_BODY()
public:
    UPROPERTY()
    FString PlayerFirstJoinName;
    
    UPROPERTY()
    EPlayerCategory PlayerCategory;
    
    UPROPERTY()
    FString PlayerGuid;
    
    UPROPERTY()
    FString PlayerRecentJoinName;
    
    ASTRO_API FPlayerProperties();
};

