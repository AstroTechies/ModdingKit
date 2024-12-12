#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "CustomGameBiomeData.generated.h"

USTRUCT(BlueprintType)
struct FCustomGameBiomeData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer GameplayTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName BiomeName;
    
    TERRAIN2_API FCustomGameBiomeData();
};

