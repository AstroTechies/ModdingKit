#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "CacheResourceGroup.generated.h"

class UItemType;

USTRUCT(BlueprintType)
struct FCacheResourceGroup {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint32 ID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemType> ItemType;
    
    ASTRO_API FCacheResourceGroup();
};

