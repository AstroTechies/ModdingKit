#pragma once
#include "CoreMinimal.h"
#include "CalledCarStatus.h"
#include "RailPostBase.h"
#include "SignalDelegate.h"
#include "CalledCarPath.h"
#include "EStationStopState.h"
#include "EStationMarkerType.h"
#include "RailPostStation.generated.h"

class ARailPostStation;
class ARailCarBase;
class ASolarBody;

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API ARailPostStation : public ARailPostBase
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable)
    FSignal OnStopModeChanged;

    UPROPERTY(BlueprintAssignable)
    FSignal OnCalledCarArrived;

    UPROPERTY(EditDefaultsOnly)
    uint8 OnlyStopIfTerminus : 1;

    UPROPERTY(SaveGame)
    EStationStopState StopMode;

protected:
    UPROPERTY(Replicated, SaveGame)
    EStationStopState CurrentStationState;

    UPROPERTY(BlueprintReadWrite, SaveGame, meta = (AllowPrivateAccess = true))
    EStationMarkerType StationMarker;

    UPROPERTY(BlueprintReadWrite, SaveGame, meta = (AllowPrivateAccess = true))
    ARailPostStation *DestinationStation;

    UPROPERTY(BlueprintReadWrite, SaveGame, meta = (AllowPrivateAccess = true))
    ARailCarBase *StoppedCar;

private:
    UPROPERTY(SaveGame)
    FCalledCarPath CalledCar;

    UPROPERTY(Replicated, SaveGame)
    int32 CurrentCarSlotConnectionID;

public:
    ARailPostStation();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

    UFUNCTION(BlueprintImplementableEvent)
    void OnStationMarkerChanged();

    UFUNCTION(BlueprintImplementableEvent)
    void OnCarCalledFailed();

    UFUNCTION(BlueprintImplementableEvent)
    void OnCarCalled();

    UFUNCTION()
    void OnCarArrivedAtDestination();

protected:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintPure)
    ARailPostStation *GetStationFromMarker(EStationMarkerType marker);

public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintPure)
    FCalledCarStatus GetCalledCarStatus();

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityTrySetStationMarker(EStationMarkerType markerType);

protected:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityTrySetDestinationStationForDockedCar(EStationMarkerType destinationMarker);

public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityTryRecallCar();

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthoritySetStopMode(EStationStopState Mode);

protected:
    UFUNCTION(BlueprintCallable)
    void AuthoritySetStationMode(EStationStopState State);

public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityHandleStationPlanetChanged(ASolarBody *previousPlanet);

    UFUNCTION(BlueprintAuthorityOnly, BlueprintPure)
    EStationMarkerType AuthorityGetNextAvailableStationMarker(EStationMarkerType currMarker, bool incrementSelection);

    UFUNCTION(BlueprintAuthorityOnly, BlueprintPure)
    EStationStopState AuthorityGetCurrentStopMode();
};
