#pragma once
#include "CoreMinimal.h"
#include "Recipe.h"
#include "SlotOrganizationRule.h"
#include "Templates/SubclassOf.h"
#include "RecipeOrganizationRule.generated.h"

class APhysicalItem;
class UItemType;

UCLASS(Blueprintable, EditInlineNew)
class URecipeOrganizationRule : public USlotOrganizationRule {
    GENERATED_BODY()
public:
    URecipeOrganizationRule();
    UFUNCTION(BlueprintCallable)
    void SetRecipe(FRecipe Recipe);
    
protected:
    UFUNCTION(BlueprintCallable)
    void GetCurrentRecipeStatus(TArray<APhysicalItem*>& outUnwantedHaveItems, TArray<TSubclassOf<UItemType>>& outMissingItems) const;
    
};

