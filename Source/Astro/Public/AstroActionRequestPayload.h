#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "AstroActionIdentifier.h"
#include "AstroActionRequestPayload.generated.h"

class UAstroAction;

USTRUCT(BlueprintType)
struct FAstroActionRequestPayload {
    GENERATED_BODY()
public:
    UPROPERTY()
    TSubclassOf<UAstroAction> ActionType;
    
    UPROPERTY()
    FAstroActionIdentifier ActionIdentifier;
    
    UPROPERTY()
    TArray<uint8> PayloadData;
    
    ASTRO_API FAstroActionRequestPayload();
};

