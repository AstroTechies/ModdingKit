#pragma once
#include "CoreMinimal.h"
#include "AstroActionIdentifier.h"
#include "Templates/SubclassOf.h"
#include "AstroActionRequestPayload.generated.h"

class UAstroAction;

USTRUCT(BlueprintType)
struct FAstroActionRequestPayload {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAstroAction> ActionType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAstroActionIdentifier ActionIdentifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<uint8> PayloadData;
    
    ASTRO_API FAstroActionRequestPayload();
};

