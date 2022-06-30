#pragma once
#include "CoreMinimal.h"
#include "DeferredObjectCreationNodeData.generated.h"

class UObject;

USTRUCT(BlueprintType)
struct FDeferredObjectCreationNodeData {
    GENERATED_BODY()
public:
    UPROPERTY(Transient)
    TArray<UObject*> LoadedAssetReferences;
    
    TERRAIN2_API FDeferredObjectCreationNodeData();
};

