#pragma once
#include "CoreMinimal.h"
#include "EIndicatorTooltipType.h"
#include "Templates/SubclassOf.h"
#include "SlotIndicatorDefinition.generated.h"

class APhysicalItem;
class UItemType;

USTRUCT(BlueprintType)
struct FSlotIndicatorDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemType> IndicatorItemType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    APhysicalItem* WhitelistCohabitationItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EIndicatorTooltipType TooltipType;
    
    ASTRO_API FSlotIndicatorDefinition();
};

