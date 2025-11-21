#pragma once
#include "CoreMinimal.h"
#include "MegastructureAppendageInfo.h"
#include "Recipe.h"
#include "MegastructureTierRecipe.generated.h"

USTRUCT(BlueprintType)
struct FMegastructureTierRecipe {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FMegastructureAppendageInfo> Appendages;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRecipe Recipe;
    
    ASTRO_API FMegastructureTierRecipe();
};

