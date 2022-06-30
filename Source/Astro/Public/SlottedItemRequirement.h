#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "SlottedItemRequirement.generated.h"

class UItemType;

USTRUCT(BlueprintType)
struct FSlottedItemRequirement {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SlotName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UItemType>> SatisfactoryItemTypes;
    
    ASTRO_API FSlottedItemRequirement();
};

