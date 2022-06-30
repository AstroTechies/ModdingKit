#pragma once
#include "CoreMinimal.h"
#include "BreadboardPrinterAnimationReplicationData.generated.h"

USTRUCT(BlueprintType)
struct FBreadboardPrinterAnimationReplicationData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    bool bPrinterIsAvailable;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    bool bPreviewIsEnabled;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    bool bPrintingIsProgressing;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    float PrintSpeed;
    
    UPROPERTY()
    float PrintheadHeight;
    
    UPROPERTY()
    float PrintheadExtension;
    
    ASTRO_API FBreadboardPrinterAnimationReplicationData();
};

