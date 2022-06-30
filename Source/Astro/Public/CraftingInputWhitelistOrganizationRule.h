#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "SlotOrganizationRule.h"
#include "CraftingInputWhitelistOrganizationRule.generated.h"

class UItemList;
class UItemType;

UCLASS(Blueprintable, EditInlineNew)
class UCraftingInputWhitelistOrganizationRule : public USlotOrganizationRule
{
    GENERATED_BODY()
public:
    UPROPERTY(EditDefaultsOnly)
    TSubclassOf<UItemList> CraftingOutputItemList;

protected:
    UPROPERTY()
    TArray<TSubclassOf<UItemType>> Whitelist;

public:
    UCraftingInputWhitelistOrganizationRule();
};
