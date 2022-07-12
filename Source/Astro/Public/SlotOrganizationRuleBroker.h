#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
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

