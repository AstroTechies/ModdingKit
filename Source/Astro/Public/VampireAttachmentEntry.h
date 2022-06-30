#pragma once
#include "CoreMinimal.h"
#include "AstroDatumRef.h"
#include "VampireAttachmentEntry.generated.h"

class UTetherAttachComponent;

USTRUCT(BlueprintType)
struct FVampireAttachmentEntry {
    GENERATED_BODY()
public:
    UPROPERTY(SaveGame)
    bool hasBeenVisited;
    
    UPROPERTY(SaveGame)
    FAstroDatumRef VampirePowerConnection;
    
    UPROPERTY(Export, SaveGame)
    UTetherAttachComponent* PreyTetherAttachComponent;
    
    ASTRO_API FVampireAttachmentEntry();
};

