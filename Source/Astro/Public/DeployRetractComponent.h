#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SignalDelegate.h"
#include "DeployRetractComponent.generated.h"

class UAnimMontage;
class UAstroAction;
class UStaticMesh;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UDeployRetractComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable)
    FSignal OnDeployedStateChanged;

    UPROPERTY(BlueprintAssignable)
    FSignal OnPendingDeployedChanged;

protected:
    UPROPERTY(BlueprintReadWrite, SaveGame, ReplicatedUsing = OnRep_IsDeployed, meta = (AllowPrivateAccess = true))
    uint8 bIsDeployed : 1;

    UPROPERTY(BlueprintReadWrite, ReplicatedUsing = OnRep_PendingDeployed, meta = (AllowPrivateAccess = true))
    uint8 bPendingDeployed : 1;

    UPROPERTY(EditDefaultsOnly)
    UAnimMontage *DeployMontage;

    UPROPERTY(EditDefaultsOnly)
    UAnimMontage *RetractMontage;

    UPROPERTY(EditDefaultsOnly)
    UStaticMesh *DeployedCollision;

    UPROPERTY(EditDefaultsOnly)
    UStaticMesh *RetractedCollision;

public:
    UDeployRetractComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

protected:
    UFUNCTION()
    void OnRep_PendingDeployed();

    UFUNCTION()
    void OnRep_IsDeployed();

    UFUNCTION()
    void OnDeployRetractMontageActionEnded(UAstroAction *montageAction);

public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityRetract();

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityDeploy();
};
