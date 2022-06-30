#pragma once
#include "CoreMinimal.h"
#include "VehicleBase.h"
#include "RailCarMovementStateDelegateDelegate.h"
#include "EnableSignalDelegate.h"
#include "SlotReference.h"
#include "Engine/EngineTypes.h"
#include "RailCarMovementReplicatedData.h"
#include "Engine/EngineBaseTypes.h"
#include "RailCarBase.generated.h"

class UControlComponent;
class USplineMeshComponent;
class APhysicalItem;
class USceneComponent;
class ARailNetwork;
class UPowerComponent;
class ARailPostBase;
class AAstroPlayerController;
class UClickQuery;

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API ARailCarBase : public AVehicleBase
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable)
    FRailCarMovementStateDelegate OnMovementStateChanged;

    UPROPERTY(BlueprintAssignable)
    FEnableSignal OnSwappedDirections;

    UPROPERTY(BlueprintReadWrite, Export, VisibleAnywhere, meta = (AllowPrivateAccess = true))
    UControlComponent *ControlComponent;

protected:
    UPROPERTY(EditDefaultsOnly)
    float MaxSpeed;

    UPROPERTY(EditDefaultsOnly)
    float DrivingControlSensitivity;

    UPROPERTY(EditDefaultsOnly)
    float LeftRightDeadzone;

    UPROPERTY(EditDefaultsOnly)
    float MinSpeedMultiplier;

    UPROPERTY(EditDefaultsOnly)
    float Length;

    UPROPERTY(EditDefaultsOnly)
    FName ForwardCaravanConnectionSlotName;

    UPROPERTY(EditDefaultsOnly)
    FName BackwardCaravanConnectionSlotName;

    UPROPERTY(EditDefaultsOnly)
    FName CaravanSlotName;

    UPROPERTY(EditDefaultsOnly)
    FComponentReference CaravanSlotPositionComponentRef;

    UPROPERTY(EditDefaultsOnly)
    FComponentReference CaravanConnectionSplineRef;

    UPROPERTY()
    FSlotReference CaravanSlot;

    UPROPERTY()
    FSlotReference ForwardCaravanConnectionSlot;

    UPROPERTY()
    FSlotReference BackwardCaravanConnectionSlot;

    UPROPERTY(Export, Transient)
    USceneComponent *CaravanSlotPositionComponent;

    UPROPERTY(Export, Transient)
    USplineMeshComponent *CaravanConnectionSpline;

    UPROPERTY(Transient)
    TSet<int32> TraversingConnections;

    UPROPERTY(Transient)
    ARailNetwork *RailNetwork;

    UPROPERTY(SaveGame, ReplicatedUsing = OnRep_MovementData)
    FRailCarMovementReplicatedData ReplicatedMovementData;

    UPROPERTY(Export, Transient)
    TArray<UPowerComponent *> PowerComponents;

    UPROPERTY(SaveGame)
    TArray<ARailPostBase *> DesiredPath;

public:
    ARailCarBase();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

protected:
    UFUNCTION(Reliable, Server)
    void ServerHandleDriverInput(float SteeringInput, float ThrottleInput);

    UFUNCTION()
    void RouteAux2ToggleUse(AAstroPlayerController *Controller, EInputEvent eventType);

    UFUNCTION()
    void RouteAux1ToggleUse(AAstroPlayerController *Controller, EInputEvent eventType);

    UFUNCTION()
    void OnRep_MovementData(FRailCarMovementReplicatedData Previous);

public:
    UFUNCTION(BlueprintPure)
    bool IsRotationInverted() const;

protected:
    UFUNCTION()
    void HandleVehicleUnmanned(AAstroPlayerController *oldDriver);

    UFUNCTION()
    void HandleVehicleManned(AAstroPlayerController *newDriver);

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
    void HandleClickQueryMutable(UClickQuery *Query);

protected:
    UFUNCTION()
    void HandleCarReleasedFromCaravanSlot(APhysicalItem *Item);

    UFUNCTION()
    void HandleCarPlacedInCaravanSlot(APhysicalItem *Item);

public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityTryStartCar(bool swapDirections);
};
