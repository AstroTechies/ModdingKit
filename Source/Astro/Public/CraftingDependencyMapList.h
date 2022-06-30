#pragma once
#include "CoreMinimal.h"
#include "CraftingOriginDependencyMap.h"
#include "Engine/DataAsset.h"
#include "CraftingDependencyMapList.generated.h"

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API UCraftingDependencyMapList : public UDataAsset
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    TArray<FCraftingOriginDependencyMap> Dependencies;

    UCraftingDependencyMapList();
};
