#pragma once
#include "CoreMinimal.h"
#include "SlotOrganizationRule.h"
#include "Templates/SubclassOf.h"
#include "WhitelistWithCanisterRule.generated.h"

class UItemList;

UCLASS(Blueprintable, EditInlineNew)
class UWhitelistWithCanisterRule : public USlotOrganizationRule {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemList> ItemTypeWhitelist;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bShowIndicators: 1;
    
public:
    UWhitelistWithCanisterRule();

};

