#pragma once
#include "CoreMinimal.h"
#include "GateObjectReplicationData.h"
#include "Components/ActorComponent.h"
#include "SignalDelegate.h"
#include "PlayerProximityEventCallbackDelegate.h"
#include "Engine/EngineTypes.h"
#include "ActorGateObjectComponent.generated.h"

class AActor;
class USkeletalMeshComponent;
class USphereComponent;
class UPrimitiveComponent;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UActorGateObjectComponent : public UActorComponent
{
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditDefaultsOnly)
    uint8 bHasPlayerProximityEvent : 1;

    UPROPERTY(AdvancedDisplay, EditDefaultsOnly)
    uint8 bAnimatesInOutroCinematic : 1;

    UPROPERTY(EditDefaultsOnly)
    float PlayerProximityEventTriggerDistance;

    UPROPERTY(BlueprintAssignable)
    FSignal OnFirstPlayerEncountered;

    UPROPERTY(BlueprintAssignable)
    FPlayerProximityEventCallback OnPlayerEnteredProximity;

    UPROPERTY(BlueprintAssignable)
    FPlayerProximityEventCallback OnPlayerExitedProximity;

    UPROPERTY(BlueprintAssignable)
    FSignal OnCanBeActivatedChanged;

    UPROPERTY(BlueprintAssignable)
    FSignal OnIsActivatedChanged;

    UPROPERTY(BlueprintReadWrite, ReplicatedUsing = OnRep_ReplicationData, meta = (AllowPrivateAccess = true))
    FGateObjectReplicationData ReplicationData;

    UPROPERTY(Transient)
    FGateObjectReplicationData PrevReplicationData;

    UPROPERTY(Export, Transient)
    USphereComponent *ProximitySphereComponent;

    UPROPERTY(Export, Transient)
    TArray<USkeletalMeshComponent *> SkeletalMeshes;

public:
    UActorGateObjectComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

protected:
    UFUNCTION()
    void OnRep_ReplicationData();

public:
    UFUNCTION()
    void OnPlayerProximitySphereEndOverlap(UPrimitiveComponent *OverlappedComponent, AActor *OtherActor, UPrimitiveComponent *OtherComp, int32 OtherBodyIndex);

    UFUNCTION()
    void OnPlayerProximitySphereBeginOverlap(UPrimitiveComponent *OverlappedComponent, AActor *OtherActor, UPrimitiveComponent *OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult);

protected:
    UFUNCTION()
    void OnOutroCinematicStarted();

    UFUNCTION()
    void OnOutroCinematicCompleted();
};
