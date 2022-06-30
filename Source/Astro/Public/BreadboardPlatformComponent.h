#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LockdownEventDelegate.h"
#include "BreadboardPlatformComponent.generated.h"

class APhysicalItem;
class UPrimitiveComponent;
class UCurveFloat;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UBreadboardPlatformComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable)
    FLockdownEvent OnLockdownEnabledChanged;

    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    UPrimitiveComponent *LockdownSpikes;

    UPROPERTY(EditDefaultsOnly)
    UCurveFloat *AnimationCurve;

protected:
    UPROPERTY(BlueprintReadWrite, SaveGame, ReplicatedUsing = OnRep_LockdownEnabledChanged, meta = (AllowPrivateAccess = true))
    bool REP_LockdownEnabled;

private:
    UPROPERTY(EditDefaultsOnly)
    float LockdownAnimationDuration;

    UPROPERTY(EditDefaultsOnly)
    float LockdownAnimationTravelDistance;

    UPROPERTY()
    APhysicalItem *OwningItem;

public:
    UBreadboardPlatformComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

    UFUNCTION()
    void OnRep_LockdownEnabledChanged();

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthoritySetLockdownEnabled(bool lockdownEnabled);
};
