#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "SlotOrganizationRulesState.h"
#include "SlotOrganizationRuleBroker.generated.h"

class AActor;

UCLASS(Blueprintable)
class USlotOrganizationRuleBroker : public UObject {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<AActor*, FSlotOrganizationRulesState> OrganizationRuleStates;
    
public:
    USlotOrganizationRuleBroker();

};

