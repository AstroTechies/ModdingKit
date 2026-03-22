#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "OneTimeTooltipList.generated.h"

class UItemType;

USTRUCT(BlueprintType)
struct FOneTimeTooltipList {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemType> TooltipItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FName> TriggeredTooltipIDs;
    
    ASTRO_API FOneTimeTooltipList();
};

