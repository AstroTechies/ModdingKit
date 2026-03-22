#pragma once
#include "CoreMinimal.h"
#include "DeferredObjectCreationNodeData.generated.h"

class UObject;

USTRUCT(BlueprintType)
struct FDeferredObjectCreationNodeData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UObject*> LoadedAssetReferences;
    
    TERRAIN2_API FDeferredObjectCreationNodeData();
};

