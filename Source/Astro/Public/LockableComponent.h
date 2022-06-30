#pragma once
#include "CoreMinimal.h"
#include "AstroEntityComponent.h"
#include "AstroDatumRef.h"
#include "LockableComponentSignalDelegate.h"
#include "LockableComponent.generated.h"

USTRUCT(BlueprintType)
struct FLockableComponent : public FAstroEntityComponent {
    GENERATED_BODY()
public:
    UPROPERTY(SaveGame)
    TArray<FAstroDatumRef> LockRefs;
    
    UPROPERTY()
    FLockableComponentSignal OnLockedStateChanged;
    
    UPROPERTY(BlueprintReadWrite, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 bIsUnlocked: 1;
    
    ASTRO_API FLockableComponent();
};

