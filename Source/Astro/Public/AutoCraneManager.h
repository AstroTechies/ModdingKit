#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AutoCraneState.h"
#include "AutoCraneOverlapTestRequest.h"
#include "AutoCraneManager.generated.h"

class ASolarBody;
class AAutoCrane;
class AActor;
class AAstroCharacter;
class APlayController;

UCLASS(Blueprintable, Blueprintable)
class UAutoCraneManager : public UObject
{
    GENERATED_BODY()
public:
private:
    UPROPERTY()
    TArray<FAutoCraneState> CraneStates;

    UPROPERTY()
    TArray<FAutoCraneOverlapTestRequest> ShapeCastRequests;

    UPROPERTY(Transient)
    TArray<AActor *> ProcessedActorCache;

    UPROPERTY(Transient)
    APlayController *PlayControllerCache;

    UPROPERTY(Transient)
    AAstroCharacter *AstroCharacterCache;

public:
    UAutoCraneManager();

private:
    UFUNCTION()
    void OnTransferItemSet(AAutoCrane *Crane);

    UFUNCTION()
    void OnTransferItemReleased(AAutoCrane *Crane);

    UFUNCTION()
    void OnTransferItemFullyEmplaced(AAutoCrane *Crane);

    UFUNCTION()
    void OnTransferItemDestroyed(AAutoCrane *Crane);

    UFUNCTION()
    void OnLocalSolarBodyChanged(ASolarBody *newBody);

    UFUNCTION()
    void OnCraneReleasedFromSlot(AAutoCrane *Crane);

    UFUNCTION()
    void OnCranePowerChanged(AAutoCrane *Crane);

    UFUNCTION()
    void OnCranePlacedInSlot(AAutoCrane *Crane);

    UFUNCTION()
    void OnCraneInputUse(AAutoCrane *Crane);

    UFUNCTION()
    void OnClientTransferProgressChanged(AAutoCrane *Crane);

    UFUNCTION()
    void OnClientCraneStateChanged(AAutoCrane *Crane);
};
