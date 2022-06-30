#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EnableSignalDelegate.h"
#include "LockingMechanismSignalDelegate.h"
#include "AstroDatumRef.h"
#include "LockChangedEventMetadata.h"
#include "ActorLockComponent.generated.h"

class ULockingMechanism;
class ULockingMechanismView;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class UActorLockComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable)
    FEnableSignal OnIsUnlockedChangedAuthority;

    UPROPERTY(BlueprintAssignable)
    FLockingMechanismSignal OnLockingMechanismOpenOrCloseAuthority;

protected:
    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    TArray<ULockingMechanismView *> LockingMechanismViews;

public:
    UActorLockComponent();
    UFUNCTION()
    void OnAuthorityLockingMechanismStateChanged(ULockingMechanism *changedLockingMechanism, const FLockChangedEventMetadata &EventData);

    UFUNCTION()
    void OnAuthorityLockedStateChanged(FAstroDatumRef lockComponentRef, const FLockChangedEventMetadata &EventData);
};
