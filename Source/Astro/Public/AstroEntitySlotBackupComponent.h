#pragma once
#include "CoreMinimal.h"
#include "AstroEntityComponent.h"
#include "Templates/SubclassOf.h"
#include "AstroEntitySlotBackupComponent.generated.h"

class APhysicalItem;

USTRUCT(BlueprintType)
struct FAstroEntitySlotBackupComponent : public FAstroEntityComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TMap<FName, TSubclassOf<APhysicalItem>> SlotContents;
    
    ASTRO_API FAstroEntitySlotBackupComponent();
};

