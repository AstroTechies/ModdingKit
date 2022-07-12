#pragma once
#include "CoreMinimal.h"
#include "EdgeVisualComponent.generated.h"

class UInstancedStaticMeshComponent;

USTRUCT(BlueprintType)
struct FEdgeVisualComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UInstancedStaticMeshComponent* MeshComponent;
    
    ASTRO_API FEdgeVisualComponent();
};

