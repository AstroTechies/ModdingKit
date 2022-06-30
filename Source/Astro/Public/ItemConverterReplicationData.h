#pragma once
#include "CoreMinimal.h"
#include "EItemConverterState.h"
#include "ActiveItemConversionProgress.h"
#include "SlotReference.h"
#include "ItemConverterReplicationData.generated.h"

USTRUCT(BlueprintType)
struct FItemConverterReplicationData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    uint8 bWantsToBeActive: 1;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    uint8 bShouldLoopProduction: 1;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    EItemConverterState ItemConverterState;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    float PowerRatio;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    TArray<FActiveItemConversionProgress> ActiveConversionProgressData;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    int32 SelectedOutputItemTypeIndex;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    TArray<FSlotReference> ExternalResourceSlotRefs;
    
    ASTRO_API FItemConverterReplicationData();
};

