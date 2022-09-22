#pragma once
#include "CoreMinimal.h"
#include "SlottedItemRequirement.h"
#include "LockingMechanismDefinition.h"
#include "SlottedItemLockingMechanismDefinition.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ASTRO_API USlottedItemLockingMechanismDefinition : public ULockingMechanismDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSlottedItemRequirement> SlottedItemRequirements;
    
    USlottedItemLockingMechanismDefinition();
};

