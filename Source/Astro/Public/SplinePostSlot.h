#pragma once
#include "CoreMinimal.h"
#include "SplinePostSlot.generated.h"

USTRUCT(BlueprintType)
struct FSplinePostSlot {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName FrontSplineSlotName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName BackSplineSlotName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bFrontSplineSlotAcceptsGeneratedConnections: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bBackSplineSlotAcceptsGeneratedConnections: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bFrontSplineSlotSpawnsStoppers: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bBackSplineSlotSpawnsStoppers: 1;
    
    ASTRO_API FSplinePostSlot();
};

