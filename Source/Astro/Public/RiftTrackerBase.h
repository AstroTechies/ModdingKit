#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
#include "ERiftTrackerGameType.h"
#include "ERiftTrackerState.h"
#include "OnRiftTrackerStateChangedDelegate.h"
#include "PhysicalItem.h"
#include "SignalDelegate.h"
#include "RiftTrackerBase.generated.h"

class AActor;
class ARiftTargetBase;
class UItemTeleportHelperComponent;
class UNavpointComponent;

UCLASS(Blueprintable)
class ASTRO_API ARiftTrackerBase : public APhysicalItem {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    ARiftTargetBase* SpawnedTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UNavpointComponent* NavpointComp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UItemTeleportHelperComponent* TeleportComp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    ERiftTrackerState TrackerState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_TrackerGameType, meta=(AllowPrivateAccess=true))
    ERiftTrackerGameType TrackerGameType;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnRiftTrackerStateChanged OnRiftTrackerStateChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnTrackerGameTypeChanged;
    
public:
    ARiftTrackerBase();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION(BlueprintCallable)
    void OnRep_TrackerGameType();
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastSetRiftTrackerState(ERiftTrackerState NewState);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ERiftTrackerState GetTrackerState();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ERiftTrackerGameType GetTrackerGameType();
    
    UFUNCTION(BlueprintCallable)
    bool FindRiftTrackerChainLocations(const TArray<AActor*>& ActorsToIgnore, TArray<FVector>& outlocArray);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthoritySetTrackerGameType(ERiftTrackerGameType NewType);
    
};

