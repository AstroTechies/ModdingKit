#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "SignalDelegate.h"
#include "PersistentLocalPlayerData.generated.h"

UCLASS(Blueprintable, BlueprintType)
class ASTRO_API UPersistentLocalPlayerData : public UObject
{
    GENERATED_BODY()
public:
    UPROPERTY(Transient)
    FSignal OnDirtied;

protected:
    UPROPERTY(BlueprintReadWrite, SaveGame, meta = (AllowPrivateAccess = true))
    bool bHasCompletedTutorial;

    UPROPERTY(BlueprintReadWrite, SaveGame, meta = (AllowPrivateAccess = true))
    bool bHasSkippedTutorial;

    UPROPERTY(BlueprintReadWrite, SaveGame, meta = (AllowPrivateAccess = true))
    bool bHasSeenIntroCutscene;

    UPROPERTY(BlueprintReadWrite, SaveGame, meta = (AllowPrivateAccess = true))
    bool bIsMultiplayerDisabled;

    UPROPERTY(SaveGame)
    uint8 LastUpdateCutsceneVersionSeen;

    UPROPERTY(SaveGame)
    TArray<uint32> EarnedItemDrivePhysicalRewardHashes;

public:
    UPersistentLocalPlayerData();
    UFUNCTION(BlueprintCallable)
    void NotifySkippedTutorial();

    UFUNCTION(BlueprintCallable)
    void NotifySeenIntroCutscene(bool wasUpdateCinematic);

    UFUNCTION(BlueprintCallable)
    void NotifyCompletedTutorial();
};
