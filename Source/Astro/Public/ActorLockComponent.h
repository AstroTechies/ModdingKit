#pragma once
#include "CoreMinimal.h"
#include "EnableSignalDelegate.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
#include "AstroDatumRef.h"
#include "LockingMechanismSignalDelegate.h"
#include "LockChangedEventMetadata.h"
#include "ActorLockComponent.generated.h"

class ULockingMechanismView;
class ULockingMechanism;

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
    UActorLockComponent();
    UFUNCTION()
    void OnAuthorityLockingMechanismStateChanged(ULockingMechanism* changedLockingMechanism, const FLockChangedEventMetadata& EventData);
    
    UFUNCTION()
    void OnAuthorityLockedStateChanged(FAstroDatumRef lockComponentRef, const FLockChangedEventMetadata& EventData);
    
};

