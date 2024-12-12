#pragma once
#include "CoreMinimal.h"
#include "AstroEntityComponentSubobject.h"
#include "LockingMechanismSignalDelegate.h"
#include "LockingMechanism.generated.h"

UCLASS(Blueprintable)
class ASTRO_API ULockingMechanism : public UAstroEntityComponentSubobject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLockingMechanismSignal OnOpenStateChanged;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 bIsOpen: 1;
    
public:
    ULockingMechanism();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsOpen() const;
    
};

