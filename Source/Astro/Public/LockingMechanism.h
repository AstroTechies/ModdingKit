#pragma once
#include "CoreMinimal.h"
#include "AstroEntityComponentSubobject.h"
#include "LockingMechanismSignalDelegate.h"
#include "LockingMechanism.generated.h"

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API ULockingMechanism : public UAstroEntityComponentSubobject
{
    GENERATED_BODY()
public:
    UPROPERTY()
    FLockingMechanismSignal OnOpenStateChanged;

private:
    UPROPERTY(SaveGame)
    uint8 bIsOpen : 1;

public:
    ULockingMechanism();
    UFUNCTION(BlueprintPure)
    bool IsOpen() const;
};
