#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SignalDelegate.h"
#include "DeployRetractComponent.generated.h"

class UAnimMontage;
class UAstroAction;
class UStaticMesh;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UDeployRetractComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnDeployedStateChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnPendingDeployedChanged;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_IsDeployed, meta=(AllowPrivateAccess=true))
    uint8 bIsDeployed: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_PendingDeployed, meta=(AllowPrivateAccess=true))
    uint8 bPendingDeployed: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimMontage* DeployMontage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimMontage* RetractMontage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* DeployedCollision;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* RetractedCollision;
    
public:
    UDeployRetractComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnRep_PendingDeployed();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_IsDeployed();
    
    UFUNCTION(BlueprintCallable)
    void OnDeployRetractMontageActionEnded(UAstroAction* montageAction);
    
public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityRetract();
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityDeploy();
    
};

