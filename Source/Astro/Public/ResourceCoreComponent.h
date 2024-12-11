#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ResourceCoreComponent.generated.h"

class UInstancedStaticMeshComponent;
class UItemComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UResourceCoreComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UItemComponent* ItemComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInstancedStaticMeshComponent* MeshComponent;
    
    UResourceCoreComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void OnItemChange();
    
};

