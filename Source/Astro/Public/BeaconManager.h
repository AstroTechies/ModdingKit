#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "BeaconManager.generated.h"

class ASolarBody;
class ABeaconBase;
class AAstroCharacter;
class APlayController;
class AAstroGameState;

UCLASS(Blueprintable, Blueprintable)
class UBeaconManager : public UObject
{
    GENERATED_BODY()
public:
private:
    UPROPERTY(Transient)
    TArray<ABeaconBase *> ActiveBeacons;

    UPROPERTY(Transient)
    TArray<ABeaconBase *> HiddenBeacons;

    UPROPERTY(Transient)
    TArray<ABeaconBase *> UpdateQueue;

    UPROPERTY(Transient)
    AAstroGameState *GameStateCache;

    UPROPERTY(Transient)
    APlayController *PlayControllerCache;

    UPROPERTY(Transient)
    AAstroCharacter *AstroCharacterCache;

public:
    UBeaconManager();

private:
    UFUNCTION()
    void OnLocalSolarBodyChanged(ASolarBody *newBody);
};
