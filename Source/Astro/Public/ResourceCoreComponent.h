#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ResourceCoreComponent.generated.h"

class UItemComponent;
class UInstancedStaticMeshComponent;

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class ASTRO_API UResourceCoreComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(Export)
    UItemComponent *ItemComponent;

    UPROPERTY(Export)
    UInstancedStaticMeshComponent *MeshComponent;

    UResourceCoreComponent();
    UFUNCTION()
    void OnItemChange();
};
