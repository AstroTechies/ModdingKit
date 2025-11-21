#pragma once
#include "CoreMinimal.h"
#include "ReplicatedMegastructurePrinterState.generated.h"

USTRUCT(BlueprintType)
struct FReplicatedMegastructurePrinterState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 CurrentSelectedTier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 CurrentPrintingTier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 SatisfiedTier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 HasPrintedFinalTier: 1;
    
    ASTRO_API FReplicatedMegastructurePrinterState();
};

