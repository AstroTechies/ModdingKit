#include "RecipeOrganizationRule.h"
#include "Templates/SubclassOf.h"

class UItemType;
class APhysicalItem;

void URecipeOrganizationRule::SetRecipe(FRecipe Recipe) {
}

void URecipeOrganizationRule::GetCurrentRecipeStatus(TArray<APhysicalItem*>& outUnwantedHaveItems, TArray<TSubclassOf<UItemType>>& outMissingItems) const {
}

URecipeOrganizationRule::URecipeOrganizationRule() {
}

