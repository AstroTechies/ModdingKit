#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/GameMode.h"
#include "GameplayTagContainer.h"
#include "CharacterSelectSignalDelegate.h"
#include "EGameLifecycleState.h"
#include "EPlanetIdentifier.h"
#include "OnCinematicTerrainPointsClearedDelegate.h"
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
class UAstroCGMModifierCategoryDefaultValuesDatabase;
class UAstroCustomGameSettingsTags;
class UItemList;
class ULevelSequencePlayer;
class UObject;
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
    FOnCinematicTerrainPointsCleared OnCinematicTerrainPointsCleared;
    
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
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UWorld> BaseGameMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UWorld> ExpansionGameMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGameplayTag> CustomGameModifiersExcludedFromSwitchTruncation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAstroCGMModifierCategoryDefaultValuesDatabase* CustomGameModifiersDefaultValueDatabase;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAstroCustomGameSettingsTags* CustomGameSettingsTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool IsFirstLaunch;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsInExpansionEnvironment;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemList> InitialKnownItemTypeList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemList> CreativeModeForceKnownItemTypeList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemList> InitialItemTypeUnlockList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemList> InitialHackedItemTypeList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UItemList>> VirusProtectionLevelsUnhackedItemTypeLists;
    
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
    AAstroGameMode(const FObjectInitializer& ObjectInitializer);

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
    
    UFUNCTION(BlueprintCallable)
    void SetIsInExpansion(bool inExpansion);
    
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
    
    UFUNCTION(BlueprintCallable)
    bool PlanetHasStartingPointCandidate(EPlanetIdentifier planetID);
    
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
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    void LoadMap(UObject* WorldContextObject, TSoftObjectPtr<UWorld> Map);
    
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
    void AuthoritySetDefaultSpawnLocation(FVector SpawnLocation);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, BlueprintPure)
    bool AuthoritySelectStartingPointFromCandiates(FVector& outStartingLocation, FRotator& outStartingRotation);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityAddStartingPointCandiateActor(const AActor* candidateActor);
    
    UFUNCTION(BlueprintCallable, Exec)
    void AddTerrainResolutionPoint(float X, float Y, float Z, float Radius);
    
};

