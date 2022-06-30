#pragma once
#include "CoreMinimal.h"
#include "BoundedModifierSceneComponent.h"
#include "ChildModifierCacheEntry.generated.h"

USTRUCT(BlueprintType)
struct FChildModifierCacheEntry {
    GENERATED_BODY()
public:
    UPROPERTY()
    TArray<FBoundedModifierSceneComponent> ChildComponents;
    
    UPROPERTY()
    bool bIsPureContainerClass;
    
    TERRAIN2_API FChildModifierCacheEntry();
};

