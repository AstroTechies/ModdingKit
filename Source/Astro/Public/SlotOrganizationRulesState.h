#pragma once
#include "CoreMinimal.h"
#include "SlotOrganizationRulesState.generated.h"

class USlotOrganizationRule;

USTRUCT(BlueprintType)
struct FSlotOrganizationRulesState {
    GENERATED_BODY()
public:
    UPROPERTY(Transient)
    TArray<TWeakObjectPtr<USlotOrganizationRule>> OrganizationRules;
    
    ASTRO_API FSlotOrganizationRulesState();
};

