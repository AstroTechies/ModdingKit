#pragma once
#include "CoreMinimal.h"
#include "AutoCraneState.generated.h"

class AAutoCrane;
class UAstroAutoCraneTransferAction;

USTRUCT(BlueprintType)
struct FAutoCraneState {
    GENERATED_BODY()
public:
    UPROPERTY(Transient)
    AAutoCrane* AutoCrane;
    
    UPROPERTY(Transient)
    UAstroAutoCraneTransferAction* TransferAction;
    
    ASTRO_API FAutoCraneState();
};

