#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ELevelingBlockVizSource.h"
#include "LevelingBlockComponent.generated.h"

class UParticleSystemComponent;
class UStaticMeshComponent;
class USlotBehaviorTerrain;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API ULevelingBlockComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    float StampSize;

private:
    UPROPERTY(Export)
    UStaticMeshComponent *PreviewMesh;

    UPROPERTY()
    USlotBehaviorTerrain *BehaviorTerrain;

    UPROPERTY(Export)
    UParticleSystemComponent *particles;

    UPROPERTY(ReplicatedUsing = OnReplicated_VisibilitySourceMask)
    uint8 VisibilityPlaced : 1;

public:
    ULevelingBlockComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    void SetPreviewVisibility(bool IsVisible, ELevelingBlockVizSource sourceId);

private:
    UFUNCTION()
    void OnReplicated_VisibilitySourceMask();

public:
    UFUNCTION(NetMulticast, Reliable)
    void MulticastStartLeveling();

    UFUNCTION(NetMulticast, Reliable)
    void MulticastPlayOrStopFX(bool bPlayParticles, bool PlaySound, bool isSuccess, bool playRespawnSound);

    UFUNCTION(BlueprintCallable)
    void CancelOperation(bool forceStopParticles);

    UFUNCTION(BlueprintCallable)
    bool AddTrueFlatStump();
};
