#pragma once
#include "CoreMinimal.h"
#include "CollectibleSimItem.generated.h"

class UStaticMeshComponent;

USTRUCT(BlueprintType)
struct FCollectibleSimItem {
    GENERATED_BODY()
public:
    UPROPERTY(Export, Transient)
    UStaticMeshComponent* Mesh;
    
    ASTRO_API FCollectibleSimItem();
};

