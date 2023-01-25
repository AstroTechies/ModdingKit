#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
#include "Components/ActorComponent.h"
#include "CalledCarState.h"
#include "ERailPostConnectionState.h"
#include "EnableSignalDelegate.h"
#include "RailPostCarSlot.h"
#include "SignalDelegate.h"
#include "SlotReference.h"
#include "StreamingPowerNodeVisualizationData.h"
#include "RailPostComponent.generated.h"

class APhysicalItem;
class ARailCarBase;
class UActuatorComponent;
class UClickQuery;
class UMaterialInstanceDynamic;
class UPrimitiveComponent;

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
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UActuatorComponent* ActuatorComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* GaugeMaterial;
    
    UPROPERTY(EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
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
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void ServerSetIsSnappedToRail();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_ShouldStopOnArrival();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_IsMovable();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_CalledCarState(FCalledCarState PreviousState);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastSetConnectionState(ERailPostConnectionState ConnectionState);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsCarRecallInProgress() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasTraversingCars() const;
    
    UFUNCTION(BlueprintCallable)
    void HandleRailNetworkCreated();
    
protected:
    UFUNCTION(BlueprintCallable)
    void HandlePowerChanged(const FStreamingPowerNodeVisualizationData& powerData);
    
    UFUNCTION(BlueprintCallable)
    void HandlePickedUp(bool isPhysicalMovement);
    
public:
    UFUNCTION(BlueprintCallable)
    void HandleIsAttachedToTerrainChanged();
    
protected:
    UFUNCTION(BlueprintCallable)
    void HandleDroppedDelayed();
    
    UFUNCTION(BlueprintCallable)
    void HandleDropped(UPrimitiveComponent* Component, const FVector& Point, const FVector& Normal);
    
    UFUNCTION(BlueprintCallable)
    void HandleDeformCompleted(float DensityDelta);
    
public:
    UFUNCTION(BlueprintCallable)
    void HandleClickQuery(UClickQuery* Query);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityTriggerUseOnStoppedCar();
    
protected:
    UFUNCTION(BlueprintCallable)
    void AuthorityHandleOxygenChanged(bool hasOxygen);
    
    UFUNCTION(BlueprintCallable)
    void AuthorityHandleItemPlacedInCaravanSlot(APhysicalItem* Item);
    
public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityCallCar();
    
};

