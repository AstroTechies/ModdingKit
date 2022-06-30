#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "PhysicalItem.h"
#include "ERepackagingTargetState.h"
#include "Repackager.generated.h"

class UAstroActionComponent;
class UAstroAction;
class UAstroRepackAction;
class AActor;

UCLASS(Blueprintable, Abstract)
class ASTRO_API ARepackager : public APhysicalItem
{
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, Export, VisibleAnywhere, meta = (AllowPrivateAccess = true))
    UAstroActionComponent *ActionComponent;

    UPROPERTY(BlueprintReadWrite, Transient, meta = (AllowPrivateAccess = true))
    TWeakObjectPtr<APhysicalItem> RepackagingTarget;

    UPROPERTY(BlueprintReadWrite, Transient, ReplicatedUsing = OnRepackagingTargetStateChanged, meta = (AllowPrivateAccess = true))
    ERepackagingTargetState TargetState;

    UPROPERTY(EditDefaultsOnly)
    TSubclassOf<UAstroRepackAction> RepackActionType;

public:
    ARepackager();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

protected:
    UFUNCTION()
    void UpdateRepackagingTarget();

    UFUNCTION(BlueprintImplementableEvent)
    void OnRepackagingTargetStateChanged();

    UFUNCTION(BlueprintImplementableEvent)
    void OnRepackageActionFinishedAuthority(UAstroAction *repackageAction);

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void InitiateRepackaging();

    UFUNCTION()
    void HandleRepackagingTargetEndPlay(AActor *Actor);
};
