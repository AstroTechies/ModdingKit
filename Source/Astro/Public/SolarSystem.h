#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "SignalDelegate.h"
#include "SolarSystem.generated.h"

class ASolarBody;
class ADayNight;
class ASun;
class AGateStation;
class AAstroPlanet;
class UWorld;

UCLASS(Blueprintable, Blueprintable)
class USolarSystem : public UObject
{
    GENERATED_BODY()
public:
    UPROPERTY()
    FSignal OnGateStationSpawned;

private:
    UPROPERTY()
    ADayNight *DayNight;

    UPROPERTY()
    ASun *Sun;

    UPROPERTY()
    AGateStation *GateStation;

    UPROPERTY()
    TArray<AAstroPlanet *> Planets;

    UPROPERTY()
    TArray<ASolarBody *> SolarBodies;

    UPROPERTY()
    UWorld *World;

public:
    USolarSystem();
};
