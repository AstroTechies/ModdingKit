#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ERiftOrbState.h"
#include "ERiftTrackerGameType.h"
#include "OnRiftOrbStateChangedDelegate.h"
#include "RiftOrbBase.generated.h"

class ARiftTargetBase;

UCLASS(Blueprintable)
class ASTRO_API ARiftOrbBase : public AActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    ARiftTargetBase* ParentTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    ERiftOrbState OrbState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    ERiftTrackerGameType OrbGameType;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnRiftOrbStateChanged OnRiftOrbStateChanged;
    
public:
    ARiftOrbBase(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastSetRiftOrbState(ERiftOrbState NewState);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ERiftOrbState GetOrbState();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ERiftTrackerGameType GetOrbGameType();
    
};

