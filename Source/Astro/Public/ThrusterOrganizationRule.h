#pragma once
#include "CoreMinimal.h"
#include "SlotOrganizationRule.h"
#include "Templates/SubclassOf.h"
#include "ThrusterOrganizationRule.generated.h"

class UItemType;

UCLASS(Blueprintable, EditInlineNew)
class ASTRO_API UThrusterOrganizationRule : public USlotOrganizationRule {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UItemType>> ItemTypeWhitelist;
    
public:
    UThrusterOrganizationRule();

};

