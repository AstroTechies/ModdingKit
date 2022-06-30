#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "SlotOrganizationRule.h"
#include "DynamicWhitelistOrganizationRule.generated.h"

class UItemType;

UCLASS(Blueprintable, EditInlineNew)
class UDynamicWhitelistOrganizationRule : public USlotOrganizationRule
{
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    TArray<TSubclassOf<UItemType>> ItemTypeWhitelist;

public:
    UDynamicWhitelistOrganizationRule();
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetWhitelist(const TArray<TSubclassOf<UItemType>> &Whitelist);

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetShowIndicators(bool showIndicators);
};
