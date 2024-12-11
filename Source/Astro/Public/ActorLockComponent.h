#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AstroDatumRef.h"
#include "EnableSignalDelegate.h"
#include "LockChangedEventMetadata.h"
#include "LockingMechanismSignalDelegate.h"
#include "ActorLockComponent.generated.h"

class ULockingMechanism;
class ULockingMechanismView;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UActorLockComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnableSignal OnIsUnlockedChangedAuthority;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLockingMechanismSignal OnLockingMechanismOpenOrCloseAuthority;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ULockingMechanismView*> LockingMechanismViews;
    
public:
    UActorLockComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void OnAuthorityLockingMechanismStateChanged(ULockingMechanism* changedLockingMechanism, const FLockChangedEventMetadata& EventData);
    
    UFUNCTION(BlueprintCallable)
    void OnAuthorityLockedStateChanged(FAstroDatumRef lockComponentRef, const FLockChangedEventMetadata& EventData);
    
};

