#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
#include "EnableSignalDelegate.h"
#include "AstroDatumRef.h"
#include "LockChangedEventMetadata.h"
#include "ActorLockableComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UActorLockableComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnableSignal OnIsUnlockedChangedAuthority;
    
    UActorLockableComponent();
    UFUNCTION()
    void OnAuthorityLockedStateChanged(FAstroDatumRef lockableComponentRef, const FLockChangedEventMetadata& EventData);
    
};

