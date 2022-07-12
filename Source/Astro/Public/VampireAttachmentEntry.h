#pragma once
#include "CoreMinimal.h"
#include "AstroDatumRef.h"
#include "VampireAttachmentEntry.generated.h"

class UTetherAttachComponent;

USTRUCT(BlueprintType)
struct FVampireAttachmentEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool hasBeenVisited;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FAstroDatumRef VampirePowerConnection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, SaveGame, meta=(AllowPrivateAccess=true))
    UTetherAttachComponent* PreyTetherAttachComponent;
    
    ASTRO_API FVampireAttachmentEntry();
};

