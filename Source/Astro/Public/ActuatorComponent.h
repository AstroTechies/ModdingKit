#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "Engine/EngineTypes.h"
#include "ActuateDelegateDelegate.h"
#include "ActuatorCableLocalState.h"
#include "ActuatorConnections.h"
#include "ActuatorConnectorLocalState.h"
#include "EAuxSlotType.h"
#include "EFullnessActuatorEventType.h"
#include "ItemHighlightInterface.h"
#include "SignalDelegate.h"
#include "SlotReference.h"
#include "ActuatorComponent.generated.h"

class AActor;
class APlayController;
class UBoxComponent;
class UClickQuery;
class UInstancedStaticMeshComponent;
class UMaterialInstanceDynamic;
class UObject;
class UPrimitiveComponent;
class USceneComponent;
class USlotsComponent;
class UTooltipComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UActuatorComponent : public UActorComponent, public IItemHighlightInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal RerouteNodeCountChanged;
    
protected:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FActuateDelegate OnActuate;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bUseShapeCast: 1;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference ShapeCastCollisionRef;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_Connections, meta=(AllowPrivateAccess=true))
    FActuatorConnections Connections;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FActuatorConnections PreviousConnections;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<int32, FActuatorCableLocalState> CableLocalState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<int32, FActuatorConnectorLocalState> ConnectorLocalState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<int32, FActuatorConnectorLocalState> RerouteNodeLocalState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UInstancedStaticMeshComponent* CableMeshes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* CableMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UInstancedStaticMeshComponent* ConnectorMeshes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* ConnectorMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UInstancedStaticMeshComponent* RerouteNodeMeshes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* RerouteNodeMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UBoxComponent* Bounds;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USlotsComponent* SlotsComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UTooltipComponent* RerouteNodeTooltip;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USceneComponent* RerouteNodeTooltipAnchor;
    
public:
    UActuatorComponent(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

private:
    UFUNCTION(BlueprintCallable)
    void OnRerouteNodeEndCursorOver(UPrimitiveComponent* TouchedComponent);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnRep_Connections();
    
public:
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastPlayConnectionAudio(const FString& AudioEvent, FVector Location, FRotator Rotation);
    
protected:
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastOnActuate(EFullnessActuatorEventType eventType);
    
private:
    UFUNCTION(BlueprintCallable)
    void LocalUseRerouteNode();
    
protected:
    UFUNCTION(BlueprintCallable)
    void HandleTracePrimitiveDestroyed(FSlotReference Slot);
    
    UFUNCTION(BlueprintCallable)
    void HandleTracePrimitiveCreated(FSlotReference Slot);
    
    UFUNCTION(BlueprintCallable)
    void HandleRemovedFromSlot();
    
private:
    UFUNCTION(BlueprintCallable)
    void HandleQueryClickable(UClickQuery* Query);
    
protected:
    UFUNCTION(BlueprintCallable)
    void HandlePlacedInSlot();
    
    UFUNCTION(BlueprintCallable)
    void HandleDestroyed(AActor* DestroyedActor);
    
public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityScheduleActuation(APlayController* Instigator, int32 tickDelay, EFullnessActuatorEventType FullnessActuatorEventType, const UObject* UniqueReference, bool makeUnique, EAuxSlotType slotTypeToTrigger);
    
private:
    UFUNCTION(BlueprintCallable)
    void AuthorityHandleSlotClick(FSlotReference clickedSlot);
    

    // Fix for true pure virtual functions not being implemented
};

