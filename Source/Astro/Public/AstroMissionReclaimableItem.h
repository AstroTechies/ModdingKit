#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "AstroMissionReclaimableItem.generated.h"

class UItemType;

USTRUCT(BlueprintType)
struct FAstroMissionReclaimableItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FString> PlayerList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemType> ItemType;
    
    ASTRO_API FAstroMissionReclaimableItem();
};

