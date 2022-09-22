#pragma once
#include "CoreMinimal.h"
#include "BoundedModifierSceneComponent.h"
#include "ChildModifierCacheEntry.generated.h"

USTRUCT(BlueprintType)
struct FChildModifierCacheEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FBoundedModifierSceneComponent> ChildComponents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsPureContainerClass;
    
    TERRAIN2_API FChildModifierCacheEntry();
};

