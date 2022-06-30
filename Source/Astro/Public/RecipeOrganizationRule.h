#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "SlotOrganizationRule.h"
#include "Recipe.h"
#include "RecipeOrganizationRule.generated.h"

class APhysicalItem;
class UItemType;

UCLASS(Blueprintable, EditInlineNew)
class URecipeOrganizationRule : public USlotOrganizationRule
{
    GENERATED_BODY()
public:
    URecipeOrganizationRule();
    UFUNCTION(BlueprintCallable)
    void SetRecipe(FRecipe Recipe);

protected:
    UFUNCTION()
    void GetCurrentRecipeStatus(TArray<APhysicalItem *> &outUnwantedHaveItems, TArray<TSubclassOf<UItemType>> &outMissingItems) const;
};
