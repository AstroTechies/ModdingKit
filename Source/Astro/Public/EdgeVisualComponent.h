#pragma once
#include "CoreMinimal.h"
#include "EdgeVisualComponent.generated.h"

class UInstancedStaticMeshComponent;

USTRUCT(BlueprintType)
struct FEdgeVisualComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInstancedStaticMeshComponent* MeshComponent;
    
    ASTRO_API FEdgeVisualComponent();
};

