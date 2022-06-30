#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "EIndicatorTooltipType.h"
#include "SlotIndicatorDefinition.generated.h"

class UItemType;
class APhysicalItem;

USTRUCT(BlueprintType)
struct FSlotIndicatorDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemType> IndicatorItemType;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    APhysicalItem* WhitelistCohabitationItem;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    EIndicatorTooltipType TooltipType;
    
    ASTRO_API FSlotIndicatorDefinition();
};

