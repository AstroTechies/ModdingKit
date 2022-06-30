#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "SlotOrganizationRule.h"
#include "WhitelistOrganizationRule.generated.h"

class UItemList;

UCLASS(Blueprintable, EditInlineNew)
class UWhitelistOrganizationRule : public USlotOrganizationRule
{
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    TSubclassOf<UItemList> ItemTypeWhitelist;

public:
    UWhitelistOrganizationRule();
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetShowIndicators(bool showIndicators);
};
