#pragma once
#include "CoreMinimal.h"
#include "ActuatorConnections.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ComponentReference -FallbackName=ComponentReference
#include "SignalDelegate.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
#include "ItemHighlightInterface.h"
#include "ActuatorConnectorLocalState.h"
#include "ActuateDelegateDelegate.h"
#include "ActuatorCableLocalState.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
#include "EFullnessActuatorEventType.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Rotator -FallbackName=Rotator
#include "SlotReference.h"
#include "EAuxSlotType.h"
#include "ActuatorComponent.generated.h"

class AActor;
class UInstancedStaticMeshComponent;
class UMaterialInstanceDynamic;
class UBoxComponent;
class USlotsComponent;
class UTooltipComponent;
class USceneComponent;
class UPrimitiveComponent;
class UClickQuery;
class APlayController;
class UObject;

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
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    UInstancedStaticMeshComponent* CableMeshes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* CableMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    UInstancedStaticMeshComponent* ConnectorMeshes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* ConnectorMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    UInstancedStaticMeshComponent* RerouteNodeMeshes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* RerouteNodeMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    UBoxComponent* Bounds;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    USlotsComponent* SlotsComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    UTooltipComponent* RerouteNodeTooltip;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    USceneComponent* RerouteNodeTooltipAnchor;
    
public:
    UActuatorComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
private:
    UFUNCTION()
    void OnRerouteNodeEndCursorOver(UPrimitiveComponent* TouchedComponent);
    
protected:
    UFUNCTION()
    void OnRep_Connections();
    
public:
    UFUNCTION(NetMulticast, Reliable)
    void MulticastPlayConnectionAudio(const FString& AudioEvent, FVector Location, FRotator Rotation);
    
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
    void HandleQueryClickable(UClickQuery* Query);
    
protected:
    UFUNCTION()
    void HandlePlacedInSlot();
    
    UFUNCTION()
    void HandleDestroyed(AActor* DestroyedActor);
    
public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityScheduleActuation(APlayController* Instigator, int32 tickDelay, EFullnessActuatorEventType FullnessActuatorEventType, const UObject* UniqueReference, bool makeUnique, EAuxSlotType slotTypeToTrigger);
    
private:
    UFUNCTION()
    void AuthorityHandleSlotClick(FSlotReference clickedSlot);
    
    
    // Fix for true pure virtual functions not being implemented
};

