#pragma once
#include "CoreMinimal.h"
#include "AstroEntityComponent.h"
#include "AstroDatumRef.h"
#include "LockComponentSignalDelegate.h"
#include "LockComponent.generated.h"

USTRUCT(BlueprintType)
struct FLockComponent : public FAstroEntityComponent {
    GENERATED_BODY()
public:
    UPROPERTY(SaveGame)
    FAstroDatumRef LockableRef;
    
    UPROPERTY()
    FLockComponentSignal OnLockedStateChanged;
    
    UPROPERTY(SaveGame)
    uint8 bIsUnlocked: 1;
    
    ASTRO_API FLockComponent();
};

