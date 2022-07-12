#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "EnableSignalDelegate.h"
#include "VehicleBase.h"
#include "RailCarMovementStateDelegateDelegate.h"
#include "SignalDelegate.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ComponentReference -FallbackName=ComponentReference
#include "SlotReference.h"
#include "RailCarMovementReplicatedData.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=EInputEvent -FallbackName=EInputEvent
#include "ERailCarMovementState.h"
#include "RailCarBase.generated.h"

class USceneComponent;
class UItemType;
class UPrimitiveComponent;
class USplineMeshComponent;
class UMaterialInstanceDynamic;
class UControlComponent;
class ARailNetwork;
class ASeatBase;
class UClickQuery;
class UPowerComponent;
class AAstroPlayerController;
class APlayController;
class APhysicalItem;

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
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    USceneComponent* CaravanSlotPositionComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    USplineMeshComponent* CaravanConnectionSpline;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* GaugeMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* WheelMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UControlComponent* ControlComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSet<int32> TraversingConnections;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ARailNetwork* RailNetwork;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_MovementData, meta=(AllowPrivateAccess=true))
    FRailCarMovementReplicatedData ReplicatedMovementData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
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
    ARailCarBase();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
protected:
    UFUNCTION(Reliable, Server)
    void ServerHandleDriverInput(float SteeringInput, float ThrottleInput, bool isCameraBackwards);
    
    UFUNCTION()
    void RouteAux2ToggleUse(AAstroPlayerController* Controller, TEnumAsByte<EInputEvent> eventType);
    
    UFUNCTION()
    void RouteAux1ToggleUse(AAstroPlayerController* Controller, TEnumAsByte<EInputEvent> eventType);
    
    UFUNCTION()
    void OnRep_MovementData(FRailCarMovementReplicatedData Previous);
    
public:
    UFUNCTION()
    void OnCarLostCursorFocus(UPrimitiveComponent* TouchedComponent);
    
    UFUNCTION()
    void OnCarGainedCursorFocus(UPrimitiveComponent* TouchedComponent);
    
protected:
    UFUNCTION(BlueprintImplementableEvent)
    void OnCaravanLengthChanged();
    
public:
    UFUNCTION(NetMulticast, Reliable)
    void MulticastOnPostConnectionsChanged();
    
    UFUNCTION(BlueprintPure)
    bool IsRotationInverted() const;
    
    UFUNCTION(BlueprintPure)
    bool HasDesiredPath() const;
    
protected:
    UFUNCTION()
    void HandleVehicleUnmanned(AAstroPlayerController* oldDriver);
    
    UFUNCTION()
    void HandleVehicleManned(AAstroPlayerController* newDriver);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void HandleUse();
    
    UFUNCTION()
    void HandleReleasedFromSlot();
    
    UFUNCTION()
    void HandleRailNetworkCreated();
    
    UFUNCTION()
    void HandlePlacedInSlot();
    
public:
    UFUNCTION()
    void HandleClickQuery(UClickQuery* Query);
    
protected:
    UFUNCTION()
    void HandleCarReleasedFromCaravanSlot(APhysicalItem* Item);
    
    UFUNCTION()
    void HandleCarPlacedInCaravanSlot(APhysicalItem* Item);
    
    UFUNCTION()
    void HandleActuateUse(TEnumAsByte<EInputEvent> InputEvent);
    
    UFUNCTION(BlueprintPure)
    float GetTotalCaravanPowerDraw() const;
    
public:
    UFUNCTION(BlueprintPure)
    ERailCarMovementState GetMovementState() const;
    
protected:
    UFUNCTION(BlueprintPure)
    int32 GetMaxCaravanLength();
    
public:
    UFUNCTION(BlueprintPure)
    float GetForwardThrottleDirectionForDriver(APlayController* Driver, bool& isCameraBackwards) const;
    
protected:
    UFUNCTION(BlueprintPure)
    ASeatBase* GetFirstSlottedSeat() const;
    
    UFUNCTION(BlueprintPure)
    int32 GetCurrentCaravanLength();
    
public:
    UFUNCTION(BlueprintPure)
    bool CaravanHasDesiredPath() const;
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityTryStartCar(bool swapDirections);
    
};

