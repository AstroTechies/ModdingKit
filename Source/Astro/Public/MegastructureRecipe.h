#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "EMegastructure.h"
#include "EMegastructureAppendageType.h"
#include "MegastructureAppendageInfo.h"
#include "MegastructureTierRecipe.h"
#include "Recipe.h"
#include "MegastructureRecipe.generated.h"

class UObject;

UCLASS(Blueprintable)
class ASTRO_API UMegastructureRecipe : public UDataAsset {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMegastructure RecipeTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FMegastructureTierRecipe> Recipes;
    
public:
    UMegastructureRecipe();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsSingleRecipe() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EMegastructure GetRecipeTarget() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    FRecipe GetRecipeAtTier(int32 Tier, const UObject* WorldContextObject) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetNumRecipes() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FMegastructureAppendageInfo> GetAppendagesAtTier(int32 Tier) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FName> GetAllToggleAppendageTags() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FMegastructureAppendageInfo> GetAllAppendagesOfType(TEnumAsByte<EMegastructureAppendageType> Type, TArray<int32>& outTierCorrespondence) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FMegastructureAppendageInfo> GetAllAppendages() const;
    
};

