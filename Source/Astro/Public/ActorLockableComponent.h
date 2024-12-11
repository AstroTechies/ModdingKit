#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AstroDatumRef.h"
#include "EnableSignalDelegate.h"
#include "LockChangedEventMetadata.h"
#include "ActorLockableComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UActorLockableComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnableSignal OnIsUnlockedChangedAuthority;
    
    UActorLockableComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void OnAuthorityLockedStateChanged(FAstroDatumRef lockableComponentRef, const FLockChangedEventMetadata& EventData);
    
};

