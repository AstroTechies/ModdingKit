#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "LockingMechanismDefinition.h"
#include "ResourceConsumptionLockingMechanismDefinition.generated.h"

class UItemType;

UCLASS(Blueprintable, EditInlineNew)
class ASTRO_API UResourceConsumptionLockingMechanismDefinition : public ULockingMechanismDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ResourceConsumptionSlotName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemType> ConsumedResource;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 RequiredResourceUnits;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ResourceUnitConsumptionTime;
    
    UResourceConsumptionLockingMechanismDefinition();
};

