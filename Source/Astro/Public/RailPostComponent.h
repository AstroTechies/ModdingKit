#pragma once
#include "CoreMinimal.h"
#include "EnableSignalDelegate.h"
#include "SignalDelegate.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
#include "SlotReference.h"
#include "RailPostCarSlot.h"
#include "CalledCarState.h"
#include "ERailPostConnectionState.h"
#include "StreamingPowerNodeVisualizationData.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
#include "RailPostComponent.generated.h"

class UMaterialInstanceDynamic;
class ARailCarBase;
class UActuatorComponent;
class UPrimitiveComponent;
class UClickQuery;
class APhysicalItem;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API URailPostComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSlotReference> RailSlots;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnCalledCarStateChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnRailConnectionAdded;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnBeginLowPower;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnBeginNoPower;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnDriverApproaching;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnDriverNoLongerApproaching;
    
protected:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnableSignal OnShouldStopOnArrivalChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FRailPostCarSlot> CarSlots;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 GaugeDynamicMaterialIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString RecallStartSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString RecallCancelSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString RecallFailSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString RecallCompleteSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UActuatorComponent* ActuatorComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* GaugeMaterial;
    
    UPROPERTY(EditAnywhere, Replicated)
    TArray<TWeakObjectPtr<ARailCarBase>> TraversingCars;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    ARailCarBase* CalledCar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_CalledCarState, meta=(AllowPrivateAccess=true))
    FCalledCarState CalledCarState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_IsMovable, meta=(AllowPrivateAccess=true))
    uint8 bIsMovable: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_ShouldStopOnArrival, meta=(AllowPrivateAccess=true))
    uint8 bShouldStopOnArrival: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 bHasBeenInitialized: 1;
    
public:
    URailPostComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
protected:
    UFUNCTION(Reliable, Server)
    void ServerSetIsSnappedToRail();
    
    UFUNCTION()
    void OnRep_ShouldStopOnArrival();
    
    UFUNCTION()
    void OnRep_IsMovable();
    
    UFUNCTION()
    void OnRep_CalledCarState(FCalledCarState PreviousState);
    
    UFUNCTION(NetMulticast, Reliable)
    void MulticastSetConnectionState(ERailPostConnectionState ConnectionState);
    
public:
    UFUNCTION(BlueprintPure)
    bool IsCarRecallInProgress() const;
    
    UFUNCTION(BlueprintPure)
    bool HasTraversingCars() const;
    
    UFUNCTION()
    void HandleRailNetworkCreated();
    
protected:
    UFUNCTION()
    void HandlePowerChanged(const FStreamingPowerNodeVisualizationData& powerData);
    
    UFUNCTION()
    void HandlePickedUp(bool isPhysicalMovement);
    
public:
    UFUNCTION()
    void HandleIsAttachedToTerrainChanged();
    
protected:
    UFUNCTION()
    void HandleDroppedDelayed();
    
    UFUNCTION()
    void HandleDropped(UPrimitiveComponent* Component, const FVector& Point, const FVector& Normal);
    
    UFUNCTION()
    void HandleDeformCompleted(float DensityDelta);
    
public:
    UFUNCTION()
    void HandleClickQuery(UClickQuery* Query);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityTriggerUseOnStoppedCar();
    
protected:
    UFUNCTION()
    void AuthorityHandleOxygenChanged(bool hasOxygen);
    
    UFUNCTION()
    void AuthorityHandleItemPlacedInCaravanSlot(APhysicalItem* Item);
    
public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityCallCar();
    
};

