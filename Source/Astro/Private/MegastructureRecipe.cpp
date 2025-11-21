#include "MegastructureRecipe.h"

UMegastructureRecipe::UMegastructureRecipe() {
    this->RecipeTarget = EMegastructure::None;
}

bool UMegastructureRecipe::IsSingleRecipe() const {
    return false;
}

EMegastructure UMegastructureRecipe::GetRecipeTarget() const {
    return EMegastructure::None;
}

FRecipe UMegastructureRecipe::GetRecipeAtTier(int32 Tier, const UObject* WorldContextObject) const {
    return FRecipe{};
}

int32 UMegastructureRecipe::GetNumRecipes() const {
    return 0;
}

TArray<FMegastructureAppendageInfo> UMegastructureRecipe::GetAppendagesAtTier(int32 Tier) const {
    return TArray<FMegastructureAppendageInfo>();
}

TArray<FName> UMegastructureRecipe::GetAllToggleAppendageTags() const {
    return TArray<FName>();
}

TArray<FMegastructureAppendageInfo> UMegastructureRecipe::GetAllAppendagesOfType(TEnumAsByte<EMegastructureAppendageType> Type, TArray<int32>& outTierCorrespondence) const {
    return TArray<FMegastructureAppendageInfo>();
}

TArray<FMegastructureAppendageInfo> UMegastructureRecipe::GetAllAppendages() const {
    return TArray<FMegastructureAppendageInfo>();
}


