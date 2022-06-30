#pragma once
#include "CoreMinimal.h"
#include "EdgeVisualComponent.generated.h"

class UInstancedStaticMeshComponent;

USTRUCT(BlueprintType)
struct FEdgeVisualComponent {
    GENERATED_BODY()
public:
    UPROPERTY(Export)
    UInstancedStaticMeshComponent* MeshComponent;
    
    ASTRO_API FEdgeVisualComponent();
};

