#pragma once
#include "CoreMinimal.h"
#include "SlotReference.h"
#include "EnableSignalDelegate.h"
#include "PhysicalItem.h"
#include "RailPostCarSlot.h"
#include "UObject/NoExportTypes.h"
#include "RailPostBase.generated.h"

class ARailCarBase;
class UActuatorComponent;
class UPrimitiveComponent;
class UClickQuery;

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API ARailPostBase : public APhysicalItem
{
    GENERATED_BODY()
public:
    UPROPERTY()
    TArray<FSlotReference> RailSlots;

protected:
    UPROPERTY(BlueprintAssignable)
    FEnableSignal OnShouldStopOnArrivalChanged;

    UPROPERTY(EditDefaultsOnly)
    TArray<FRailPostCarSlot> CarSlots;

    UPROPERTY(Export, VisibleAnywhere)
    UActuatorComponent *ActuatorComponent;

    UPROPERTY(Replicated)
    TArray<TWeakObjectPtr<ARailCarBase>> TraversingCars;

    UPROPERTY()
    TMap<FName, int32> RailConnections;

    UPROPERTY(ReplicatedUsing = OnRep_IsMovable)
    uint8 bIsMovable : 1;

    UPROPERTY(SaveGame, ReplicatedUsing = OnRep_ShouldStopOnArrival)
    uint8 bShouldStopOnArrival : 1;

    UPROPERTY(SaveGame)
    uint8 bHasBeenInitialized : 1;

public:
    ARailPostBase();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

protected:
    UFUNCTION()
    void OnRep_ShouldStopOnArrival();

    UFUNCTION()
    void OnRep_IsMovable();

    UFUNCTION()
    void HandleUse();

    UFUNCTION()
    void HandlePickedUp(bool isPhysicalMovement);

    UFUNCTION()
    void HandleDroppedDelayed();

    UFUNCTION()
    void HandleDropped(UPrimitiveComponent *Component, const FVector &Point, const FVector &Normal);

public:
    UFUNCTION()
    void HandleClickQuery(UClickQuery *Query);

protected:
    UFUNCTION()
    void AuthorityHandleOxygenChanged(bool hasOxygen);

    UFUNCTION()
    void AuthorityHandleItemPlacedInCaravanSlot(APhysicalItem *Item);
};
