#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ELevelingBlockVizSource.h"
#include "LevelingBlockComponent.generated.h"

class UParticleSystemComponent;
class USlotBehaviorTerrain;
class UStaticMeshComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API ULevelingBlockComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StampSize;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* PreviewMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USlotBehaviorTerrain* BehaviorTerrain;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UParticleSystemComponent* Particles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnReplicated_VisibilitySourceMask, meta=(AllowPrivateAccess=true))
    uint8 VisibilityPlaced: 1;
    
public:
    ULevelingBlockComponent(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    void SetPreviewVisibility(bool IsVisible, ELevelingBlockVizSource sourceId);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnReplicated_VisibilitySourceMask();
    
public:
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastStartLeveling();
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastPlayOrStopFX(bool bPlayParticles, bool PlaySound, bool isSuccess, bool playRespawnSound);
    
    UFUNCTION(BlueprintCallable)
    void CancelOperation(bool forceStopParticles);
    
    UFUNCTION(BlueprintCallable)
    bool AddTrueFlatStump();
    
};

