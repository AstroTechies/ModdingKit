#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "EGameLifecycleState.h"
#include "OnSessionsSearchCompleteNotifyDelegate.h"
#include "GameFramework/GameMode.h"
#include "RestartPlayerSignalDelegate.h"
#include "OnGameLifecycleStateChangedDelegate.h"
#include "SignalDelegate.h"
#include "SpawnPointList.h"
#include "CharacterSelectSignalDelegate.h"
#include "PlayerJoinSignalDelegate.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "AstroGameMode.generated.h"

class ASolarBody;
class UWorld;
class ULevelSequencePlayer;
class UItemList;
class UStorageChassisComponent;
class AActor;
class APlayController;
class USolarSystem;

UCLASS(Blueprintable, NonTransient)
class ASTRO_API AAstroGameMode : public AGameMode
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable)
    FOnSessionsSearchCompleteNotify SessionsSearch;

    UPROPERTY(BlueprintAssignable)
    FOnGameLifecycleStateChanged OnGameLifecycleStateChanged;

    UPROPERTY(BlueprintAssignable)
    FSignal OnMatchStarted;

    UPROPERTY(BlueprintAssignable)
    FRestartPlayerSignal OnPlayerRestarted;

    UPROPERTY(BlueprintAssignable)
    FPlayerJoinSignal OnPlayerJoin;

    UPROPERTY(BlueprintAssignable)
    FCharacterSelectSignal OnClientCharacterSelected;

    UPROPERTY(EditAnywhere)
    TSoftObjectPtr<UWorld> NewGameMap;

protected:
    UPROPERTY(EditDefaultsOnly)
    TSubclassOf<UItemList> InitialKnownItemTypeList;

    UPROPERTY(EditDefaultsOnly)
    TSubclassOf<UItemList> CreativeModeForceKnownItemTypeList;

    UPROPERTY(EditDefaultsOnly)
    TSubclassOf<UItemList> InitialItemTypeUnlockList;

    UPROPERTY(EditDefaultsOnly)
    int32 InitialResearchPointBalance;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    uint8 bPlayerStartsWithTerrainTool : 1;

    UPROPERTY(EditDefaultsOnly)
    uint8 bAllowsMultiplayer : 1;

    UPROPERTY(EditDefaultsOnly)
    uint8 bIsTutorialMode : 1;

    UPROPERTY(EditDefaultsOnly)
    uint8 bDeferStartListenServer : 1;

    UPROPERTY(EditDefaultsOnly)
    bool NewGamesUseIntroCinematic;

    UPROPERTY(EditDefaultsOnly)
    bool PlayIntroOnce;

    UPROPERTY(EditDefaultsOnly)
    bool NewGamesUseTitleMenu;

    UPROPERTY(EditDefaultsOnly)
    bool EnableSavedGamesAutomatically;

private:
    UPROPERTY(Export)
    UStorageChassisComponent *DefaultSpawnPoint;

    UPROPERTY(Export)
    TArray<UStorageChassisComponent *> UnmappedSpawnPoints;

    UPROPERTY()
    TMap<ASolarBody *, FSpawnPointList> SpawnPointsBySolarBody;

    UPROPERTY(Transient)
    TArray<AActor *> CandidateStartingPoints;

    UPROPERTY(Transient)
    ULevelSequencePlayer *IntroSequencePlayer;

public:
    AAstroGameMode();
    UFUNCTION()
    void UnregisterSpawnPointActorAttachmentsComponent(UStorageChassisComponent *spawnPoint);

    UFUNCTION(BlueprintCallable)
    void SwitchLifecycleState(EGameLifecycleState NewState, const FString &Reason);

    UFUNCTION(Exec)
    void SpawnPlayerFromHistory(int64 NetworkUuid);

    UFUNCTION(BlueprintCallable)
    void SetPlayerHasSeenIntro(bool playerHasSeenIntro);

    UFUNCTION(BlueprintCallable)
    void SetMultiplayerEnabled(bool bIsEnabled);

    UFUNCTION(Exec)
    void ServerSaveGameName(const FString &Name);

    UFUNCTION(Exec)
    void ServerSaveGameAndQuit();

    UFUNCTION(Exec)
    void ServerSaveGame();

    UFUNCTION(Exec)
    void ServerNewGame();

    UFUNCTION(Exec)
    bool ServerLoadGameName(const FString &Name);

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void RespawnPlayer(APlayController *Player, FVector locationOnDeath);

    UFUNCTION()
    void RegisterSpawnPointActorAttachmentsComponent(UStorageChassisComponent *spawnPoint);

private:
    UFUNCTION()
    void OnOutroCinematicComplete();

    UFUNCTION()
    void OnNewGameInitiated();

    UFUNCTION()
    void OnIntroCinematicFinished();

    UFUNCTION()
    void OnIntroCinematicComplete();

public:
    UFUNCTION()
    void OnFullLicenseDetected();

    UFUNCTION(BlueprintCallable)
    void MovePlayersToSpawnPositions();

    UFUNCTION(BlueprintPure)
    static bool IsPackagedBuild();

    UFUNCTION(BlueprintPure)
    bool IsMultiplayerEnabled() const;

private:
    UFUNCTION()
    void InitializeForSolarSystem(USolarSystem *SolarSystem);

public:
    UFUNCTION()
    void HandleControllingLocalPlayerLoggedOut();

    UFUNCTION(BlueprintPure)
    UStorageChassisComponent *GetDefaultSpawnPoint() const;

    UFUNCTION(BlueprintPure)
    EGameLifecycleState GetCurrentLifecycleState();

    UFUNCTION(BlueprintCallable)
    void ClearCinematicTerrainPoints();

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthoritySetDefaultSpawnLocation(FVector spawnLocation);

    UFUNCTION(BlueprintAuthorityOnly, BlueprintPure)
    bool AuthoritySelectStartingPointFromCandiates(FVector &outStartingLocation, FRotator &outStartingRotation);

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityAddStartingPointCandiateActor(const AActor *candidateActor);

    UFUNCTION(Exec)
    void AddTerrainResolutionPoint(float X, float Y, float Z, float Radius);
};
