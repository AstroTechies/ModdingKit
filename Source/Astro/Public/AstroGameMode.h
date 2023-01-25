#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Rotator -FallbackName=Rotator
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=GameMode -FallbackName=GameMode
#include "CharacterSelectSignalDelegate.h"
#include "GameFramework/GameMode.h"
#include "EGameLifecycleState.h"
#include "OnGameLifecycleStateChangedDelegate.h"
#include "OnSessionsSearchCompleteNotifyDelegate.h"
#include "PlayerJoinSignalDelegate.h"
#include "RestartPlayerSignalDelegate.h"
#include "SignalDelegate.h"
#include "SpawnPointList.h"
#include "Templates/SubclassOf.h"
#include "AstroGameMode.generated.h"

class AActor;
class APlayController;
class ASolarBody;
class UItemList;
class ULevelSequencePlayer;
class USolarSystem;
class UStorageChassisComponent;
class UWorld;

UCLASS(Blueprintable, NonTransient)
class ASTRO_API AAstroGameMode : public AGameMode {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnSessionsSearchCompleteNotify SessionsSearch;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnGameLifecycleStateChanged OnGameLifecycleStateChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnMatchStarted;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRestartPlayerSignal OnPlayerRestarted;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPlayerJoinSignal OnPlayerJoin;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCharacterSelectSignal OnClientCharacterSelected;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UWorld> NewGameMap;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemList> InitialKnownItemTypeList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemList> CreativeModeForceKnownItemTypeList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemList> InitialItemTypeUnlockList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 InitialResearchPointBalance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bPlayerStartsWithTerrainTool: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bAllowsMultiplayer: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bIsTutorialMode: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bDeferStartListenServer: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool NewGamesUseIntroCinematic;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool PlayIntroOnce;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool NewGamesUseTitleMenu;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool EnableSavedGamesAutomatically;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStorageChassisComponent* DefaultSpawnPoint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UStorageChassisComponent*> UnmappedSpawnPoints;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<ASolarBody*, FSpawnPointList> SpawnPointsBySolarBody;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AActor*> CandidateStartingPoints;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ULevelSequencePlayer* IntroSequencePlayer;
    
public:
    AAstroGameMode();
    UFUNCTION(BlueprintCallable)
    void UnregisterSpawnPointActorAttachmentsComponent(UStorageChassisComponent* spawnPoint);
    
    UFUNCTION(BlueprintCallable)
    void SwitchLifecycleState(EGameLifecycleState NewState, const FString& Reason);
    
    UFUNCTION(Exec)
    void SpawnPlayerFromHistory(int64 NetworkUuid);
    
    UFUNCTION(BlueprintCallable)
    void SetPlayerHasSeenIntro(bool playerHasSeenIntro);
    
    UFUNCTION(BlueprintCallable)
    void SetMultiplayerEnabled(bool bIsEnabled);
    
    UFUNCTION(BlueprintCallable, Exec)
    void ServerSaveGameName(const FString& Name);
    
    UFUNCTION(BlueprintCallable, Exec)
    void ServerSaveGameAndQuit();
    
    UFUNCTION(BlueprintCallable, Exec)
    void ServerSaveGame();
    
    UFUNCTION(BlueprintCallable, Exec)
    void ServerNewGame();
    
    UFUNCTION(BlueprintCallable, Exec)
    bool ServerLoadGameName(const FString& Name);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void RespawnPlayer(APlayController* Player, FVector locationOnDeath);
    
    UFUNCTION(BlueprintCallable)
    void RegisterSpawnPointActorAttachmentsComponent(UStorageChassisComponent* spawnPoint);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnOutroCinematicComplete();
    
    UFUNCTION(BlueprintCallable)
    void OnNewGameInitiated();
    
    UFUNCTION(BlueprintCallable)
    void OnIntroCinematicFinished();
    
    UFUNCTION(BlueprintCallable)
    void OnIntroCinematicComplete();
    
public:
    UFUNCTION(BlueprintCallable)
    void OnFullLicenseDetected();
    
    UFUNCTION(BlueprintCallable)
    void MovePlayersToSpawnPositions();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsPackagedBuild();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsMultiplayerEnabled() const;
    
private:
    UFUNCTION(BlueprintCallable)
    void InitializeForSolarSystem(USolarSystem* SolarSystem);
    
public:
    UFUNCTION(BlueprintCallable)
    void HandleIntroCinematicSkip();
    
    UFUNCTION(BlueprintCallable)
    void HandleControllingLocalPlayerLoggedOut();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UStorageChassisComponent* GetDefaultSpawnPoint() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EGameLifecycleState GetCurrentLifecycleState();
    
    UFUNCTION(BlueprintCallable)
    void ClearCinematicTerrainPoints();
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthoritySetDefaultSpawnLocation(FVector spawnLocation);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, BlueprintPure)
    bool AuthoritySelectStartingPointFromCandiates(FVector& outStartingLocation, FRotator& outStartingRotation);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityAddStartingPointCandiateActor(const AActor* candidateActor);
    
    UFUNCTION(BlueprintCallable, Exec)
    void AddTerrainResolutionPoint(float X, float Y, float Z, float Radius);
    
};

