#pragma once
#include "CoreMinimal.h"
#include "EAstroStartingSlotItem.h"
#include "AstroStartingItemSettings.generated.h"

USTRUCT(BlueprintType)
struct FAstroStartingItemSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<EAstroStartingSlotItem> UtilitySlotItems;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<EAstroStartingSlotItem> BackpackSlotItems;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<EAstroStartingSlotItem> ToolSlotItems;
    
    ASTRO_API FAstroStartingItemSettings();
};

