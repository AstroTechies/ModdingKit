#pragma once
#include "CoreMinimal.h"
#include "SlotIndicatorDefinition.h"
#include "SubslotIndicatorType.generated.h"

class UMaterialInterface;
class UPrimitiveComponent;
class UTooltipComponent;

USTRUCT(BlueprintType)
struct FSubslotIndicatorType {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlotIndicatorDefinition IndicatorDefinition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    UPrimitiveComponent* SlotIndicator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UMaterialInterface*> SlotIndicatorOriginalMaterials;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    UTooltipComponent* IndicatorTooltipComponent;
    
    ASTRO_API FSubslotIndicatorType();
};

