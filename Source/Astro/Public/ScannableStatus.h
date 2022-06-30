#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EScannableType.h"
#include "UObject/NoExportTypes.h"
#include "ScannableStatus.generated.h"

class ASolarBody;

USTRUCT(BlueprintType)
struct FScannableStatus {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    FName ScannableName;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    FVector Location;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<ASolarBody> LocalSolarBody;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    EScannableType ScannableType;
    
    UPROPERTY()
    FGuid NavpointGUID;
    
    ASTRO_API FScannableStatus();
};

