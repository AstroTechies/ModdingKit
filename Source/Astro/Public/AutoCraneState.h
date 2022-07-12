#pragma once
#include "CoreMinimal.h"
#include "AutoCraneState.generated.h"

class AAutoCrane;
class UAstroAutoCraneTransferAction;

USTRUCT(BlueprintType)
struct FAutoCraneState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AAutoCrane* AutoCrane;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAstroAutoCraneTransferAction* TransferAction;
    
    ASTRO_API FAutoCraneState();
};

