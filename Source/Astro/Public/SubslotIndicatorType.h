#pragma once
#include "CoreMinimal.h"
#include "SlotIndicatorDefinition.h"
#include "SubslotIndicatorType.generated.h"

class UPrimitiveComponent;
class UMaterialInterface;
class UTooltipComponent;

USTRUCT(BlueprintType)
struct FSubslotIndicatorType {
    GENERATED_BODY()
public:
    UPROPERTY()
    FSlotIndicatorDefinition IndicatorDefinition;
    
    UPROPERTY(Export, Transient)
    UPrimitiveComponent* SlotIndicator;
    
    UPROPERTY(Transient)
    TArray<UMaterialInterface*> SlotIndicatorOriginalMaterials;
    
    UPROPERTY(Export, Transient)
    UTooltipComponent* IndicatorTooltipComponent;
    
    ASTRO_API FSubslotIndicatorType();
};

