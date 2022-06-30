#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EnableSignalDelegate.h"
#include "LockChangedEventMetadata.h"
#include "AstroDatumRef.h"
#include "ActorLockableComponent.generated.h"

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class UActorLockableComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable)
    FEnableSignal OnIsUnlockedChangedAuthority;

    UActorLockableComponent();
    UFUNCTION()
    void OnAuthorityLockedStateChanged(FAstroDatumRef lockableComponentRef, const FLockChangedEventMetadata &EventData);
};
