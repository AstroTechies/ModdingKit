#pragma once
#include "CoreMinimal.h"
#include "CraftingOriginDependencyMap.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=DataAsset -FallbackName=DataAsset
#include "CraftingDependencyMapList.generated.h"

UCLASS(Blueprintable)
class ASTRO_API UCraftingDependencyMapList : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FCraftingOriginDependencyMap> Dependencies;
    
    UCraftingDependencyMapList();
};

