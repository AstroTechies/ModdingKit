#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RiftTargetBase.generated.h"

class ARiftOrbBase;
class ARiftTrackerBase;
class UItemTeleportHelperComponent;

UCLASS(Blueprintable)
class ASTRO_API ARiftTargetBase : public AActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 NumOrbs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    ARiftTrackerBase* ParentTracker;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_SpawnedOrbs, meta=(AllowPrivateAccess=true))
    TArray<ARiftOrbBase*> SpawnedOrbs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UItemTeleportHelperComponent* TeleportComp;
    
public:
    ARiftTargetBase(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnRep_SpawnedOrbs();
    
};

