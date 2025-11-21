#pragma once
#include "CoreMinimal.h"
#include "TrueFlatModuleState.generated.h"

USTRUCT(BlueprintType)
struct FTrueFlatModuleState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bIsBeingHeld: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 bIsSlotted: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bIsMaterialized: 1;
    
    ASTRO_API FTrueFlatModuleState();
};

