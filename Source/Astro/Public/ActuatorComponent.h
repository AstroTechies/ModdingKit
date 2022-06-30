#pragma once
#include "CoreMinimal.h"
#include "ItemHighlightInterface.h"
#include "Components/ActorComponent.h"
#include "ActuateDelegateDelegate.h"
#include "SignalDelegate.h"
#include "Engine/EngineTypes.h"
#include "ActuatorConnections.h"
#include "ActuatorCableLocalState.h"
#include "SlotReference.h"
#include "ActuatorConnectorLocalState.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "EFullnessActuatorEventType.h"
#include "ActuatorComponent.generated.h"

class UInstancedStaticMeshComponent;
class UMaterialInstanceDynamic;
class UBoxComponent;
class USlotsComponent;
class UTooltipComponent;
class USceneComponent;
class UPrimitiveComponent;
class APlayController;
class UClickQuery;
class AActor;
class UObject;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UActuatorComponent : public UActorComponent, public IItemHighlightInterface
{
    GENERATED_BODY()
public:
    UPROPERTY()
    FSignal RerouteNodeCountChanged;

protected:
    UPROPERTY(BlueprintAssignable)
    FActuateDelegate OnActuate;

private:
    UPROPERTY(EditDefaultsOnly)
    uint8 bUseShapeCast : 1;

    UPROPERTY(EditDefaultsOnly)
    FComponentReference ShapeCastCollisionRef;

    UPROPERTY(SaveGame, ReplicatedUsing = OnRep_Connections)
    FActuatorConnections Connections;

    UPROPERTY(Transient)
    FActuatorConnections PreviousConnections;

    UPROPERTY(Transient)
    TMap<int32, FActuatorCableLocalState> CableLocalState;

    UPROPERTY(Transient)
    TMap<int32, FActuatorConnectorLocalState> ConnectorLocalState;

    UPROPERTY(Transient)
    TMap<int32, FActuatorConnectorLocalState> RerouteNodeLocalState;

    UPROPERTY(Export, Transient)
    UInstancedStaticMeshComponent *CableMeshes;

    UPROPERTY(Transient)
    UMaterialInstanceDynamic *CableMaterial;

    UPROPERTY(Export, Transient)
    UInstancedStaticMeshComponent *ConnectorMeshes;

    UPROPERTY(Transient)
    UMaterialInstanceDynamic *ConnectorMaterial;

    UPROPERTY(Export, Transient)
    UInstancedStaticMeshComponent *RerouteNodeMeshes;

    UPROPERTY(Transient)
    UMaterialInstanceDynamic *RerouteNodeMaterial;

    UPROPERTY(Export, Transient)
    UBoxComponent *Bounds;

    UPROPERTY(Export, Transient)
    USlotsComponent *SlotsComponent;

    UPROPERTY(Export, Transient)
    UTooltipComponent *RerouteNodeTooltip;

    UPROPERTY(Export, Transient)
    USceneComponent *RerouteNodeTooltipAnchor;

public:
    UActuatorComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

private:
    UFUNCTION()
    void OnRerouteNodeEndCursorOver(UPrimitiveComponent *TouchedComponent);

protected:
    UFUNCTION()
    void OnRep_Connections();

public:
    UFUNCTION(NetMulticast, Reliable)
    void MulticastPlayConnectionAudio(const FString &AudioEvent, FVector Location, FRotator Rotation);

protected:
    UFUNCTION(NetMulticast, Reliable)
    void MulticastOnActuate(EFullnessActuatorEventType eventType);

private:
    UFUNCTION()
    void LocalUseRerouteNode();

protected:
    UFUNCTION()
    void HandleTracePrimitiveDestroyed(FSlotReference Slot);

    UFUNCTION()
    void HandleTracePrimitiveCreated(FSlotReference Slot);

    UFUNCTION()
    void HandleRemovedFromSlot();

private:
    UFUNCTION()
    void HandleQueryClickable(UClickQuery *Query);

protected:
    UFUNCTION()
    void HandlePlacedInSlot();

    UFUNCTION()
    void HandleDestroyed(AActor *DestroyedActor);

public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityScheduleActuation(APlayController *Instigator, int32 tickDelay, EFullnessActuatorEventType FullnessActuatorEventType, const UObject *UniqueReference, bool makeUnique);

private:
    UFUNCTION()
    void AuthorityHandleSlotClick(FSlotReference clickedSlot);

    // Fix for true pure virtual functions not being implemented
};
