#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "GameFramework/Actor.h"
#include "UObject/NoExportTypes.h"
#include "PreDisconnectedDelegate.h"
#include "SlotConnectionReplicationData.h"
#include "SlotReference.h"
#include "OnApproximateSplineMeshLengthChangedDelegate.h"
#include "SlotConnectionClientMotionData.h"
#include "SlotConnectionMotionReplicationData.h"
#include "SignalDelegate.h"
#include "Engine/EngineTypes.h"
#include "InputCoreTypes.h"
#include "SlotConnection.generated.h"

class UItemType;
class UStaticMeshComponent;
class UStaticMesh;
class ASlotConnection;
class APhysicsConstraintActor;
class UInstancedStaticMeshComponent;
class USplineMeshComponent;
class UPrimitiveComponent;
class UAdaptiveTickComponent;
class APhysicalItem;
class USceneComponent;
class UAstroSaveCustomArchiveProxy;

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API ASlotConnection : public AActor
{
    GENERATED_BODY()
public:
    UPROPERTY(EditDefaultsOnly)
    TSubclassOf<UItemType> ExtenderItemTypeUnbundled;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FVector ExtenderPlacementOffset;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float PhysicsConstraintConeStiffness;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float PhysicsConstraintTwistStiffness;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float PhysicsConstraintLinearStiffness;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float JointOffset;

    UPROPERTY(EditDefaultsOnly)
    float Swing1LimitDegrees;

    UPROPERTY(EditDefaultsOnly)
    float Swing2LimitDegrees;

    UPROPERTY(EditDefaultsOnly)
    float TwistLimitDegrees;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta = (AllowPrivateAccess = true))
    float AdjustDistance;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float BreakDistance;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float DragDistance;

    UPROPERTY(EditAnywhere)
    float ComponentBreakDistance;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta = (AllowPrivateAccess = true))
    float MinConnectionLength;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta = (AllowPrivateAccess = true))
    bool UseSourceScale;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta = (AllowPrivateAccess = true))
    float StretchForce;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta = (AllowPrivateAccess = true))
    float SourceForceBias;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta = (AllowPrivateAccess = true))
    float StretchDampening;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta = (AllowPrivateAccess = true))
    bool Stretchy;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta = (AllowPrivateAccess = true))
    bool CanAttachAny;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float ConnectorVerticalOffsetWhileDragging;

    UPROPERTY(EditAnywhere)
    TSubclassOf<ASlotConnection> ConnectionSpawnedByIndicator;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    UStaticMesh *ConnectorMesh;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FVector ConnectorLocation;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float ConnectorHoverInSlotForwardOffset;

    UPROPERTY(BlueprintReadWrite, SaveGame, meta = (AllowPrivateAccess = true))
    FSlotReference SourceSlot;

    UPROPERTY(BlueprintReadWrite, SaveGame, meta = (AllowPrivateAccess = true))
    FSlotReference TargetSlot;

    UPROPERTY(Transient)
    APhysicsConstraintActor *SlotConstraint;

    UPROPERTY(SaveGame)
    uint8 ConstraintBuilt : 1;

    UPROPERTY(SaveGame)
    uint8 ConstraintSleeping : 1;

    UPROPERTY(BlueprintReadWrite, SaveGame, meta = (AllowPrivateAccess = true))
    uint8 Built : 1;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta = (AllowPrivateAccess = true))
    uint8 Visible : 1;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta = (AllowPrivateAccess = true))
    uint8 TargetTetherLocation : 1;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta = (AllowPrivateAccess = true))
    uint8 clickable : 1;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta = (AllowPrivateAccess = true))
    uint8 BreakImmediate : 1;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta = (AllowPrivateAccess = true))
    uint8 CanConnectComponents : 1;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta = (AllowPrivateAccess = true))
    uint8 CanConnectSlots : 1;

    UPROPERTY(EditDefaultsOnly)
    uint8 bHighlightTargetedPhysicalItem : 1;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta = (AllowPrivateAccess = true))
    uint8 OverrideUnbreakable : 1;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    uint8 UsePhysicsConstraint : 1;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    uint8 Destroying : 1;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    uint8 IsIndicator : 1;

    UPROPERTY(EditAnywhere)
    uint8 ClickableAfterRelease : 1;

    UPROPERTY(EditDefaultsOnly)
    uint8 bCarriesOxygen : 1;

    UPROPERTY(EditDefaultsOnly)
    uint8 bTraceIgnoreSelf : 1;

    UPROPERTY(EditDefaultsOnly)
    uint8 bTraceIgnoreParent : 1;

    UPROPERTY(EditDefaultsOnly)
    uint8 bNoProximitySlotSelect : 1;

    UPROPERTY(EditAnywhere)
    uint8 SourceTense : 1;

    UPROPERTY(EditAnywhere)
    uint8 TargetTense : 1;

    UPROPERTY(EditAnywhere)
    uint8 TargetConnectorTense : 1;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    uint8 UseSplineCable : 1;

    UPROPERTY(EditDefaultsOnly)
    uint8 AlignWithSurfaceNormal : 1;

    UPROPERTY(EditAnywhere)
    float GravityTension;

    UPROPERTY(EditAnywhere)
    float CurveTension;

    UPROPERTY(BlueprintReadWrite, SaveGame, meta = (AllowPrivateAccess = true))
    float CurrentConnectionLength;

    UPROPERTY(BlueprintReadWrite, SaveGame, meta = (AllowPrivateAccess = true))
    float ConnectionLength;

    UPROPERTY(EditAnywhere)
    float SegmentLength;

    UPROPERTY(EditAnywhere)
    float SegmentScale;

    UPROPERTY(EditDefaultsOnly)
    TArray<FName> ConnectionPreventionTags;

    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    UStaticMeshComponent *Connector;

    UPROPERTY(BlueprintReadWrite, SaveGame, meta = (AllowPrivateAccess = true))
    AActor *HangingActor;

    UPROPERTY(BlueprintReadWrite, Export, VisibleAnywhere, meta = (AllowPrivateAccess = true))
    UInstancedStaticMeshComponent *SegmentComponent;

    UPROPERTY(BlueprintReadWrite, Export, VisibleAnywhere, meta = (AllowPrivateAccess = true))
    USplineMeshComponent *SplineMeshComponent;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    float CableExtendSpeed;

    UPROPERTY(EditDefaultsOnly)
    FString AttachAudioEventName;

    UPROPERTY(EditDefaultsOnly)
    FString DetachAudioEventName;

    UPROPERTY(EditDefaultsOnly)
    FString SlotHoverAudioEventName;

    UPROPERTY(EditDefaultsOnly)
    FString FullyRetractedAudioEventName;

    UPROPERTY(EditDefaultsOnly)
    FString ConnectionLengthIncreaseAudioEventName;

    UPROPERTY(EditDefaultsOnly)
    FString ConnectionLengthDecreaseAudioEventName;

    UPROPERTY(EditDefaultsOnly)
    float ConnectionLengthAudioEventInterval;

    UPROPERTY(EditDefaultsOnly)
    FName ConnectionLengthRTPCName;

    UPROPERTY(BlueprintAssignable)
    FOnApproximateSplineMeshLengthChanged OnApproximateSplineLengthChanged;

    UPROPERTY(BlueprintAssignable)
    FSignal OnDisconnectedSignal;

    UPROPERTY(BlueprintAssignable)
    FPreDisconnected OnPreDisconnected;

    UPROPERTY()
    FSignal OnSourceSlotChanged;

private:
    UPROPERTY(ReplicatedUsing = OnRep_SlotData)
    FSlotConnectionReplicationData m_replicationData;

    UPROPERTY(Replicated)
    FSlotConnectionMotionReplicationData m_replicationMotionData;

    UPROPERTY(Export, VisibleAnywhere)
    UAdaptiveTickComponent *AdaptiveTickComponent;

    UPROPERTY(Export, Transient)
    USceneComponent *SourcePoint;

    UPROPERTY(Export, Transient)
    USceneComponent *TargetPoint;

    UPROPERTY(Transient)
    FTimerHandle DestroyTimer;

    UPROPERTY(Export, Transient)
    UPrimitiveComponent *ConnectedComponent;

    UPROPERTY(Transient)
    FSlotReference LastHoverSlot;

public:
    ASlotConnection();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

private:
    UFUNCTION(Server, Unreliable, WithValidation)
    void ServerUpdateClientMotion(FSlotConnectionClientMotionData motionData);

public:
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerReleaseCable();

    UFUNCTION(Reliable, Server, WithValidation)
    void ServerDoTimedDestruction();

private:
    UFUNCTION()
    void SaveGameSerializeCustom(UAstroSaveCustomArchiveProxy *proxy);

public:
    UFUNCTION(BlueprintCallable)
    void PlaceExtenderForHeldCable(APhysicalItem *ExtenderBundle);

    UFUNCTION()
    void OnTetherAttachComponentHasOxygenChanged(bool bHasOxygen);

private:
    UFUNCTION()
    void OnSelfDestroyed(AActor *Actor);

public:
    UFUNCTION()
    void OnSelfClicked(AActor *Actor, FKey Key);

    UFUNCTION(BlueprintImplementableEvent)
    void OnSegmentSpawn();

    UFUNCTION(BlueprintImplementableEvent)
    void OnSegmentDestroy();

private:
    UFUNCTION()
    void OnRep_SlotData();

protected:
    UFUNCTION(BlueprintImplementableEvent)
    void OnIsCarryingOxygenChanged(bool bIsCarryingOxygen);

public:
    UFUNCTION(BlueprintNativeEvent)
    void OnHoverOtherSlot(FSlotReference Slot);

private:
    UFUNCTION()
    void OnFullyRetracted();

public:
    UFUNCTION(BlueprintNativeEvent)
    void OnDisconnected();

    UFUNCTION(BlueprintNativeEvent)
    void OnConnected();

private:
    UFUNCTION(NetMulticast, Unreliable)
    void MulticastBeginHoverOverSlotFX();

public:
    UFUNCTION(BlueprintCallable)
    void MakeConnection(FSlotReference Slot);

    UFUNCTION(BlueprintCallable)
    void MakeComponentConnection(UPrimitiveComponent *Component, const FVector &Location, const FVector &Normal);

    UFUNCTION(BlueprintPure)
    FSlotReference GetOtherSlot(FSlotReference Slot) const;

    UFUNCTION(BlueprintPure)
    FVector GetEndpointLocation(bool allowConnections);

    UFUNCTION(BlueprintPure)
    FVector GetCurveNormal(float Alpha, float Tensile) const;

    UFUNCTION(BlueprintPure)
    FVector GetCurveLocation(float Alpha, float Tensile) const;

    UFUNCTION(BlueprintCallable)
    bool GetConnectionMidpoint(FVector &outVector);

    UFUNCTION(BlueprintPure)
    bool CanConnect(FSlotReference Slot);

    UFUNCTION(BlueprintCallable)
    void Break();
};
