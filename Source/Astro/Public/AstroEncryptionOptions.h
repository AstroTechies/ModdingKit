#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AstroEncryptionOptions.generated.h"

USTRUCT(BlueprintType)
struct ASTRO_API FAstroEncryptionOptions {
    GENERATED_BODY()
public:
    UPROPERTY(EditDefaultsOnly)
    bool bLimitedTime;
    
    UPROPERTY(EditDefaultsOnly)
    FDateTime UnlockTime;
    
    UPROPERTY(EditDefaultsOnly)
    FDateTime EndTime;
    
    FAstroEncryptionOptions();
};

