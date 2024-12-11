#pragma once
#include "CoreMinimal.h"
#include "SlotOrganizationRule.h"
#include "Templates/SubclassOf.h"
#include "WhitelistOrganizationRule.generated.h"

class UItemList;

UCLASS(Blueprintable, EditInlineNew)
class UWhitelistOrganizationRule : public USlotOrganizationRule {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemList> ItemTypeWhitelist;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bShowIndicators: 1;
    
public:
    UWhitelistOrganizationRule();

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetShowIndicators(bool showIndicators);
    
};

