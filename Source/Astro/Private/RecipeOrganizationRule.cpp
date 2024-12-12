#include "RecipeOrganizationRule.h"
#include "Templates/SubclassOf.h"

URecipeOrganizationRule::URecipeOrganizationRule() {
    this->bEjectUnwantedItems = true;
}

void URecipeOrganizationRule::SetRecipe(FRecipe Recipe) {
}

void URecipeOrganizationRule::GetCurrentRecipeStatus(TArray<APhysicalItem*>& outUnwantedHaveItems, TArray<TSubclassOf<UItemType>>& outMissingItems) const {
}


