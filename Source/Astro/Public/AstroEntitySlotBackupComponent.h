#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "AstroEntityComponent.h"
#include "AstroEntitySlotBackupComponent.generated.h"

class APhysicalItem;

USTRUCT(BlueprintType)
struct FAstroEntitySlotBackupComponent : public FAstroEntityComponent {
    GENERATED_BODY()
public:
    UPROPERTY(SaveGame)
    TMap<FName, TSubclassOf<APhysicalItem>> SlotContents;
    
    ASTRO_API FAstroEntitySlotBackupComponent();
};

