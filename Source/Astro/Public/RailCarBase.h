#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Engine/EngineBaseTypes.h"
#include "ERailCarMovementState.h"
#include "EnableSignalDelegate.h"
#include "RailCarMovementReplicatedData.h"
#include "RailCarMovementStateDelegateDelegate.h"
#include "SignalDelegate.h"
#include "SlotReference.h"
#include "Templates/SubclassOf.h"
#include "VehicleBase.h"
#include "RailCarBase.generated.h"

class AAstroPlayerController;
class APhysicalItem;
class APlayController;
class ARailNetwork;
class ASeatBase;
class UClickQuery;
class UControlComponent;
class UItemType;
class UMaterialInstanceDynamic;
class UPowerComponent;
class UPrimitiveComponent;
class USceneComponent;
class USplineMeshComponent;

UCLASS(Blueprintable)
class ASTRO_API ARailCarBase : public AVehicleBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRailCarMovementStateDelegate OnMovementStateChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnableSignal OnSwappedDirections;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnBeginLowPower;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnBeginNoPower;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnDesiredPathStarted;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnDesiredPathCancelled;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnDesiredPathCompleted;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnSteerablePostAvailable;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnSteerablePostUnavailable;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AccelerationRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LowPowerSpeedMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LeftRightDeadzone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Length;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SteeringControlDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemType> SteerablePostItemType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 GaugeDynamicMaterialIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 WheelsDynamicMaterialIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WheelRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ForwardCaravanConnectionSlotName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName BackwardCaravanConnectionSlotName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName CaravanSlotName;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference CaravanSlotPositionComponentRef;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference CaravanConnectionSplineRef;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlotReference CaravanSlot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlotReference ForwardCaravanConnectionSlot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlotReference BackwardCaravanConnectionSlot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USceneComponent* CaravanSlotPositionComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USplineMeshComponent* CaravanConnectionSpline;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* GaugeMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* WheelMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UControlComponent* ControlComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSet<int32> TraversingConnections;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ARailNetwork* RailNetwork;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_MovementData, meta=(AllowPrivateAccess=true))
    FRailCarMovementReplicatedData ReplicatedMovementData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UPowerComponent*> PowerComponents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bForceInvertOnEnds: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString StartTrainLoopAudioEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString StopTrainLoopAudioEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString StartRecallAudioEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString RecallInProgressAudioEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString StopRecallAudioEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString StartTrainBlockedAudioEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString StopTrainBlockedAudioEvent;
    
public:
    ARailCarBase(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void ServerHandleDriverInput(float SteeringInput, float ThrottleInput, bool isCameraBackwards);
    
    UFUNCTION(BlueprintCallable)
    void RouteAux2ToggleUse(AAstroPlayerController* Controller, TEnumAsByte<EInputEvent> eventType);
    
    UFUNCTION(BlueprintCallable)
    void RouteAux1ToggleUse(AAstroPlayerController* Controller, TEnumAsByte<EInputEvent> eventType);
    
    UFUNCTION(BlueprintCallable)
    void OnRep_MovementData(FRailCarMovementReplicatedData Previous);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnCarLostCursorFocus(UPrimitiveComponent* TouchedComponent);
    
    UFUNCTION(BlueprintCallable)
    void OnCarGainedCursorFocus(UPrimitiveComponent* TouchedComponent);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnCaravanLengthChanged();
    
public:
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastOnPostConnectionsChanged();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsRotationInverted() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasDesiredPath() const;
    
protected:
    UFUNCTION(BlueprintCallable)
    void HandleVehicleUnmanned(AAstroPlayerController* oldDriver);
    
    UFUNCTION(BlueprintCallable)
    void HandleVehicleManned(AAstroPlayerController* newDriver);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void HandleUse();
    
    UFUNCTION(BlueprintCallable)
    void HandleReleasedFromSlot();
    
    UFUNCTION(BlueprintCallable)
    void HandleRailNetworkCreated();
    
    UFUNCTION(BlueprintCallable)
    void HandlePlacedInSlot();
    
public:
    UFUNCTION(BlueprintCallable)
    void HandleClickQuery(UClickQuery* Query);
    
protected:
    UFUNCTION(BlueprintCallable)
    void HandleCarReleasedFromCaravanSlot(APhysicalItem* Item);
    
    UFUNCTION(BlueprintCallable)
    void HandleCarPlacedInCaravanSlot(APhysicalItem* Item);
    
    UFUNCTION(BlueprintCallable)
    void HandleActuateUse(TEnumAsByte<EInputEvent> InputEvent);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetTotalCaravanPowerDraw() const;
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ERailCarMovementState GetMovementState() const;
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetMaxCaravanLength();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetForwardThrottleDirectionForDriver(APlayController* Driver, bool& isCameraBackwards) const;
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ASeatBase* GetFirstSlottedSeat() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetCurrentCaravanLength();
    
    UFUNCTION(BlueprintCallable)
    void ConsumeLeftTriggerToggle();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CaravanHasDesiredPath() const;
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityTryStartCar(bool swapDirections);
    
};

