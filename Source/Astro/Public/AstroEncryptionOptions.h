#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AstroEncryptionOptions.generated.h"

USTRUCT(BlueprintType)
struct ASTRO_API FAstroEncryptionOptions {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bLimitedTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDateTime UnlockTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDateTime EndTime;
    
    FAstroEncryptionOptions();
};

