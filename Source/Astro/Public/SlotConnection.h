#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
#include "GameFramework/Actor.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=TimerHandle -FallbackName=TimerHandle
//CROSS-MODULE INCLUDE V2: -ModuleName=InputCore -ObjectName=Key -FallbackName=Key
#include "OnApproximateSplineMeshLengthChangedDelegate.h"
#include "PreDisconnectedDelegate.h"
#include "SignalDelegate.h"
#include "SlotConnectionClientMotionData.h"
#include "SlotConnectionMotionReplicationData.h"
#include "SlotConnectionReplicationData.h"
#include "SlotReference.h"
#include "Templates/SubclassOf.h"
#include "SlotConnection.generated.h"

class APhysicalItem;
class APhysicsConstraintActor;
class ASlotConnection;
class UAdaptiveTickComponent;
class UAstroSaveCustomArchiveProxy;
class UInstancedStaticMeshComponent;
class UItemType;
class UPrimitiveComponent;
class USceneComponent;
class USplineMeshComponent;
class UStaticMesh;
class UStaticMeshComponent;

UCLASS(Blueprintable)
class ASTRO_API ASlotConnection : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemType> ExtenderItemTypeUnbundled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector ExtenderPlacementOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PhysicsConstraintConeStiffness;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PhysicsConstraintTwistStiffness;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PhysicsConstraintLinearStiffness;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float JointOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Swing1LimitDegrees;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Swing2LimitDegrees;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TwistLimitDegrees;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float AdjustDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BreakDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DragDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ComponentBreakDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float MinConnectionLength;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool UseSourceScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float StretchForce;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float SourceForceBias;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float StretchDampening;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool Stretchy;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool CanAttachAny;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ConnectorVerticalOffsetWhileDragging;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ASlotConnection> ConnectionSpawnedByIndicator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* ConnectorMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector ConnectorLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ConnectorHoverInSlotForwardOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FSlotReference SourceSlot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FSlotReference TargetSlot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    APhysicsConstraintActor* SlotConstraint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 ConstraintBuilt: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 ConstraintSleeping: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 Built: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 Visible: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 TargetTetherLocation: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 clickable: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 BreakImmediate: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 CanConnectComponents: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 CanConnectSlots: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bHighlightTargetedPhysicalItem: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 OverrideUnbreakable: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 UsePhysicsConstraint: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 Destroying: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 IsIndicator: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 ClickableAfterRelease: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bCarriesOxygen: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bTraceIgnoreSelf: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bTraceIgnoreParent: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bNoProximitySlotSelect: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 SourceTense: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 TargetTense: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 TargetConnectorTense: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 UseSplineCable: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 AlignWithSurfaceNormal: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float GravityTension;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CurveTension;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float CurrentConnectionLength;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float ConnectionLength;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SegmentLength;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SegmentScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> ConnectionPreventionTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* Connector;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    AActor* HangingActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInstancedStaticMeshComponent* SegmentComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USplineMeshComponent* SplineMeshComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CableExtendSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString AttachAudioEventName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString DetachAudioEventName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString SlotHoverAudioEventName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString FullyRetractedAudioEventName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ConnectionLengthIncreaseAudioEventName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ConnectionLengthDecreaseAudioEventName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ConnectionLengthAudioEventInterval;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ConnectionLengthRTPCName;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnApproximateSplineMeshLengthChanged OnApproximateSplineLengthChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnDisconnectedSignal;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPreDisconnected OnPreDisconnected;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnSourceSlotChanged;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_SlotData, meta=(AllowPrivateAccess=true))
    FSlotConnectionReplicationData m_replicationData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    FSlotConnectionMotionReplicationData m_replicationMotionData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAdaptiveTickComponent* AdaptiveTickComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USceneComponent* SourcePoint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USceneComponent* TargetPoint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FTimerHandle DestroyTimer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UPrimitiveComponent* ConnectedComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FSlotReference LastHoverSlot;
    
public:
    ASlotConnection();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
private:
    UFUNCTION(BlueprintCallable, Server, Unreliable, WithValidation)
    void ServerUpdateClientMotion(FSlotConnectionClientMotionData motionData);
    
public:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerReleaseCable();
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerDoTimedDestruction();
    
private:
    UFUNCTION(BlueprintCallable)
    void SaveGameSerializeCustom(UAstroSaveCustomArchiveProxy* proxy);
    
public:
    UFUNCTION(BlueprintCallable)
    void PlaceExtenderForHeldCable(APhysicalItem* ExtenderBundle);
    
    UFUNCTION(BlueprintCallable)
    void OnTetherAttachComponentHasOxygenChanged(bool bHasOxygen);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnSelfDestroyed(AActor* Actor);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnSelfClicked(AActor* Actor, FKey Key);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSegmentSpawn();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSegmentDestroy();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnRep_SlotData();
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnIsCarryingOxygenChanged(bool bIsCarryingOxygen);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnHoverOtherSlot(FSlotReference Slot);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnFullyRetracted();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnDisconnected();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnConnected();
    
private:
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void MulticastBeginHoverOverSlotFX();
    
public:
    UFUNCTION(BlueprintCallable)
    void MakeConnection(FSlotReference Slot, bool PlaySounds);
    
    UFUNCTION(BlueprintCallable)
    void MakeComponentConnection(UPrimitiveComponent* Component, const FVector& Location, const FVector& Normal);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FSlotReference GetOtherSlot(FSlotReference Slot) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetEndpointLocation(bool allowConnections);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetCurveNormal(float Alpha, float Tensile) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetCurveLocation(float Alpha, float Tensile) const;
    
    UFUNCTION(BlueprintCallable)
    bool GetConnectionMidpoint(FVector& outVector);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanConnect(FSlotReference Slot);
    
    UFUNCTION(BlueprintCallable)
    void BreakImmediately();
    
    UFUNCTION(BlueprintCallable)
    void Break();
    
};

