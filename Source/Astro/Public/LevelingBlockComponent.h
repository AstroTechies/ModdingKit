#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
#include "ELevelingBlockVizSource.h"
#include "LevelingBlockComponent.generated.h"

class UStaticMeshComponent;
class USlotBehaviorTerrain;
class UParticleSystemComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API ULevelingBlockComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StampSize;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* PreviewMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USlotBehaviorTerrain* BehaviorTerrain;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UParticleSystemComponent* particles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnReplicated_VisibilitySourceMask, meta=(AllowPrivateAccess=true))
    uint8 VisibilityPlaced: 1;
    
public:
    ULevelingBlockComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
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

