#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EMegastructureAppendageType.h"
#include "SlotReference.h"
#include "IndicatorInfo.generated.h"

class UMaterialInstanceDynamic;
class UPrimitiveComponent;

USTRUCT(BlueprintType)
struct FIndicatorInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EMegastructureAppendageType> AppendageType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FSlotReference SlotRef;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, SaveGame, meta=(AllowPrivateAccess=true))
    UPrimitiveComponent* VisualPrimitive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, SaveGame, meta=(AllowPrivateAccess=true))
    UPrimitiveComponent* ButtonIndicator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* PrintingMaterialDynamic;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 SlotIndicatorIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FTransform IndicatorTransform;
    
    ASTRO_API FIndicatorInfo();
};

