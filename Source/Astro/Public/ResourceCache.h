#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "ResourceCache.generated.h"

class UItemType;

USTRUCT(BlueprintType)
struct FResourceCache {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemType> ResourceType;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    int32 Amount;
    
    ASTRO_API FResourceCache();
};

