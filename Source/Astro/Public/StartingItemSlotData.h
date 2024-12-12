#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "StartingItemSlotData.generated.h"

class UItemType;

USTRUCT(BlueprintType)
struct FStartingItemSlotData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemType> ItemType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool StartFull;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FName SlotName;
    
    ASTRO_API FStartingItemSlotData();
};

