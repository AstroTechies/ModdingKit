#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/GameState.h"
#include "CreativePaintMaterialMapping.h"
#include "DeformationParamsT2.h"
#include "PackedVoxelMaterialInfo.h"
#include "ActiveTerrainColorChangedDelegate.h"
#include "AstroCustomGameSettings.h"
#include "AstroCustomGameState.h"
#include "AstroOneTimeTooltipState.h"
#include "AstroRemotePlayerChunk.h"
#include "DebugLocation.h"
#include "EAchievementProgressionState.h"
#include "EAstroAchievementKeys.h"
#include "ECollectionReward.h"
#include "EDonationReward.h"
#include "EPlanetIdentifier.h"
#include "EWandererRealityTearOpenState.h"
#include "EnableSignalDelegate.h"
#include "FirewallStateUpdatedDelegate.h"
#include "GlitchWalkersFinalEncounterCompletedDelegate.h"
#include "GlitchWalkersFinalEncounterResetDelegate.h"
#include "GlitchWalkersFinalEncounterStartedDelegate.h"
#include "ItemCollectionAchievementProgress.h"
#include "OnCollectionRewardsChangedDelegate.h"
#include "OnCurrentResearchPointBalanceChangedDelegate.h"
#include "OnDonationRewardChangedDelegate.h"
#include "OnItemTypeListChangedDelegate.h"
#include "OutroSequenceActorCreatedDelegate.h"
#include "PlanetFirewallStates.h"
#include "PlanetVirusProtectionKitState.h"
#include "ProbeUnlockState.h"
#include "ScannableStatus.h"
#include "SignalDelegate.h"
#include "StarterItemCreatedDelegate.h"
#include "StormState.h"
#include "StormStates.h"
#include "StormsEnabledStateChangedDelegate.h"
#include "Templates/SubclassOf.h"
#include "TutorialSignalDelegate.h"
#include "VirusProtectionStateUpdatedDelegate.h"
#include "WanderRealityTearOpenStateEventDelegate.h"
#include "AstroGameState.generated.h"

class AActor;
class AAstroCharacter;
class AAstroCustomGameManager;
class AAstroMissionsManager;
class AAstroPlanet;
class AAstroPlayerController;
class AAstroStorm;
class AAstroStormSpawnLocationCandidate;
class ALevelSequenceActor;
class APhysicalItem;
class ARailNetwork;
class AShuttle;
class ASolarBody;
class ASplineNetwork;
class UActivation;
class UActorClassList;
class UActorEntityLinkComponent;
class UActuatorQueue;
class UAstroSaveCustomArchiveProxy;
class UAstropediaAssetManager;
class UItemType;
class ULevelSequencePlayer;
class UMegastructureManager;
class UParticleSystem;
class URewardState;
class URewardSystem;
class USoundBase;

UCLASS(Blueprintable)
class AAstroGameState : public AGameState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    float GameSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    float SolarTimeScaleMultiplierCreative;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTutorialSignal OnObjectiveSet;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTutorialSignal OnTutorialNotify;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStarterItemCreated OnStarterItemCreated;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnCurrentResearchPointBalanceChanged OnResearchPointBalanceChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnItemTypeListChanged OnKnownItemTypesChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnItemTypeListChanged OnUnlockedItemTypesChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnItemTypeListChanged OnHackedItemTypesChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnCreativeModeCatalogUnlockedChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnableSignal OnCreativeModeEnabledChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnAchievementProgressionDisabledChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnableSignal OnCreativeFreeFuelChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnOutroCinematicStarted;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOutroSequenceActorCreated OnOutroSequenceActorCreated;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnOutroCinematicCompleted;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnDonationRewardChanged OnDonationRewardsChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnCollectionRewardsChanged OnCollectionRewardsChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UActivation* DeformToolActivation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<APhysicalItem>> AvailableRecipes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    bool TutorialInteractionMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool TutorialSlowMovement;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FName CurrentObjective;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FName> TutorialNotifiedList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<APhysicalItem*> SpawnedStartingItems;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> ActiveThemes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool MapLoadedFromSave;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool SaveGamePermitted;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float WindValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FAstroCustomGameState customGameState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FAstroOneTimeTooltipState OneTimeTooltipState;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnMissionsManagerCreated;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnCustomGameManagerCreated;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal UnlockedVintageProbesChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWanderRealityTearOpenStateEvent OnWandererRealityTearOpenChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TMap<EAstroAchievementKeys, int32> CountAchievementProgress;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TMap<EAstroAchievementKeys, float> FloatAchievementProgress;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TMap<EAstroAchievementKeys, FItemCollectionAchievementProgress> CollectionAchievementProgress;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FActiveTerrainColorChanged OnActiveCreativeTerrainColorChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FString, UActorClassList*> LTEClasses;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UActorClassList* NonPersistantActorClasses;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FString, UActorClassList*> MissionIdToObjectPlacementMap;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVirusProtectionStateUpdated OnVirusProtectionStateUpdated;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFirewallStateUpdated OnFirewallStateUpdated;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGlitchWalkersFinalEncounterStarted OnGlitchWalkersFinalEncounterStarted;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGlitchWalkersFinalEncounterReset OnGlitchWalkersFinalEncounterReset;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGlitchWalkersFinalEncounterCompleted OnGlitchWalkersFinalEncounterCompleted;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStormsEnabledStateChanged OnStormsEnabledStateChanged;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 bIsMultiplayerEnabled: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_IsOutroCinematicActive, meta=(AllowPrivateAccess=true))
    uint8 bIsOutroCinematicActive: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<AActor*> NewPlayerSpawnLocations;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<AActor*> SpawnLocations;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, SaveGame, meta=(AllowPrivateAccess=true))
    UActorEntityLinkComponent* EntityLinkComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=BroadcastResearchPointBalanceChanged, meta=(AllowPrivateAccess=true))
    float CurrentResearchPointBalance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    float CurrentResearchPointsPerMinute;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=BroadcastKnownItemsChanged, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UItemType>> KnownItemTypes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=BroadcastUnlockedItemsChanged, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UItemType>> UnlockedItemTypes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=BroadcastHackedItemsChanged, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UItemType>> HackedItemTypes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    TArray<FScannableStatus> ScannableStatuses;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=BroadcastUnlockedVintageProbesChanged, meta=(AllowPrivateAccess=true))
    TArray<FProbeUnlockState> ProbeUnlockStates;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ULevelSequencePlayer* OutroCinematicPlayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ALevelSequenceActor* OutroSequenceActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FDebugLocation> DebugLocations;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_CreativeModeSettings, meta=(AllowPrivateAccess=true))
    uint8 bAchievementProgressionDisabled: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_CreativeModeSettings, meta=(AllowPrivateAccess=true))
    uint8 bIsIndividualDedicatedServerGame: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_CreativeModeSettings, meta=(AllowPrivateAccess=true))
    uint8 bCreativeModeActive: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_CreativeModeSettings, meta=(AllowPrivateAccess=true))
    uint8 bCreativeAllCatalogItemsUnlocked: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 bCreativeFreeOxygenOn: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_CreativeModeSettings, meta=(AllowPrivateAccess=true))
    uint8 bCreativeFreeFuelOn: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 bCreativeInvisibleToHazardsOn: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 bCreativeInvincibleOn: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 bCreativeUnlimitedBackpackPowerOn: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float MatCollectionGameSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAstropediaAssetManager* AstropediaAssetManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    UActuatorQueue* ActuatorQueue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_RailNetwork, meta=(AllowPrivateAccess=true))
    ARailNetwork* RailNetwork;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_SplineNetwork, meta=(AllowPrivateAccess=true))
    ASplineNetwork* SplineNetwork;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    URewardSystem* RewardSystem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    URewardState* RewardState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMegastructureManager* MegastructureManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_MissionsManager, meta=(AllowPrivateAccess=true))
    AAstroMissionsManager* MissionsManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    AAstroCustomGameManager* CustomGameManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FAstroRemotePlayerChunk> RemotePlayerHistory;
    
    // UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    // Missed Property: DeformationCompleteEvents
    // FunctionSignature is nullptr, cannot deduce function for 'MulticastInlineDelegateProperty DeformationCompleteEvents./Script/Astro.AstroGameState:DeformationCompleteEvents'

    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool PreventCompletedMissionPlacements;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FStormStates> PerPlanetStormStates;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TMap<EPlanetIdentifier, FPlanetVirusProtectionKitState> PerPlanetVirusProtectionStates;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_PlanetVirusProtectionStates, meta=(AllowPrivateAccess=true))
    TArray<FPlanetVirusProtectionKitState> PlanetVirusProtectionStates;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    int32 InstalledRootKitCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TMap<EPlanetIdentifier, FPlanetFirewallStates> PerPlanetFirewallStates;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FPlanetFirewallStates> PlanetFirewallStates;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    bool StormsEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    bool StormsMissionBlocked;
    
    UPROPERTY(EditAnywhere, SaveGame, ReplicatedUsing=OnRep_DonationRewardsUpdated, meta=(AllowPrivateAccess=true))
    uint32 EnabledDonationRewards;
    
    UPROPERTY(EditAnywhere, SaveGame, ReplicatedUsing=OnRep_CollectionRewardsUpdated, meta=(AllowPrivateAccess=true))
    uint32 EnabledCollectionRewards;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FName LastEnabledEXOVaultName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    bool IsInExpansionEnvironment;
    
    UPROPERTY(EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint32 ActiveDLCEntitlements;
    
    AAstroGameState(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    void UpdateStormStates(float dt);
    
    UFUNCTION(BlueprintCallable)
    void UpdateMaxStormCount(AAstroPlanet* Planet, int32 newMaxStormCount);
    
    UFUNCTION(BlueprintCallable)
    void UnregisterSpawnedStartingItem(APhysicalItem* Item);
    
    UFUNCTION(BlueprintCallable)
    bool TrySubmitHackedGatewayComplete(EPlanetIdentifier planetID);
    
    UFUNCTION(BlueprintCallable)
    bool TrySubmitCounterhackKeySubmittedToGateway(EPlanetIdentifier planetID, int32 StormID);
    
    UFUNCTION(BlueprintCallable)
    void SyncSettingsFromServer(bool IsCustomGame, const FAstroCustomGameSettings& CustomGameSettings, const FAstroCustomGameState& customGameStateToSync);
    
    UFUNCTION(BlueprintCallable)
    void SetStormsMissionBlocked(bool NewState);
    
    UFUNCTION(BlueprintCallable)
    void SetStormsEnabled(bool NewState);
    
    UFUNCTION(BlueprintCallable)
    void SetPreventCompletedMissionPlacements();
    
    UFUNCTION(BlueprintCallable)
    void SetOxygenFreeCreative(bool OxygenFree);
    
    UFUNCTION(BlueprintCallable)
    void SetNewGameDropshipSequenceActive(bool IsActive);
    
    UFUNCTION(BlueprintCallable)
    void SetIsInExpansion(bool inExpansion);
    
    UFUNCTION(BlueprintCallable)
    void SetInvisibleToHazardsCreative(bool InvisibleToHazards);
    
    UFUNCTION(BlueprintCallable)
    void SetInvincibleCreative(bool Invincible);
    
    UFUNCTION(BlueprintCallable)
    void SetFuelFreeCreative(bool FreeFuelEnabled);
    
    UFUNCTION(BlueprintCallable)
    void SetEntitledMegatechContentActivated();
    
    UFUNCTION(BlueprintCallable)
    void SetCurrentObjective(FName Name);
    
    UFUNCTION(BlueprintCallable)
    void SetCreativeModeActive(bool CreativeMode);
    
    UFUNCTION(BlueprintCallable)
    void SetCatalogUnlockedCreative(bool CatalogUnlocked);
    
    UFUNCTION(BlueprintCallable)
    void SetBackpackPowerUnlimitedCreative(bool BackpackPowerUnlimited);
    
    UFUNCTION(BlueprintCallable)
    void SetAchievementProgressionDisabledCreative(bool AchievementProgressionDisabled);
    
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void ServerNotifyPlayerMadeLandfall(AAstroPlayerController* PlayerController);
    
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void ServerNotifyPlayerLeftSession(AAstroPlayerController* PlayerController);
    
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void ServerNotifyPlayerJoinedSession(AAstroPlayerController* PlayerController);
    
protected:
    UFUNCTION(BlueprintCallable)
    void SaveGameSerializeCustom(UAstroSaveCustomArchiveProxy* proxy);
    
public:
    UFUNCTION(BlueprintCallable)
    void RemoveNewPlayerSpawnLocation(AActor* Spawn);
    
    UFUNCTION(BlueprintCallable)
    void RemoveActivePlacementThemes(const TArray<FName>& themeNames);
    
    UFUNCTION(BlueprintCallable)
    void RemoveActivePlacementTheme(const FName ThemeName);
    
    UFUNCTION(BlueprintCallable)
    void RegisterSpawnedStartingItem(APhysicalItem* Item);
    
    UFUNCTION(BlueprintCallable)
    void RegisterPlanetForStorms(AAstroPlanet* Planet, bool overrideExistingPlanetStormStates);
    
    UFUNCTION(BlueprintCallable)
    bool PlanetHasStormState(EPlanetIdentifier planetID);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnRep_SplineNetwork(ASplineNetwork* previousValue) const;
    
    UFUNCTION(BlueprintCallable)
    void OnRep_RailNetwork(ARailNetwork* previousValue);
    
    UFUNCTION(BlueprintCallable)
    void OnRep_PlanetVirusProtectionStates();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_MissionsManager(AAstroMissionsManager* previousValue);
    
    UFUNCTION(BlueprintCallable)
    void OnRep_IsOutroCinematicActive();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnRep_DonationRewardsUpdated();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnRep_CustomGameManager(AAstroCustomGameManager* previousValue);
    
    UFUNCTION(BlueprintCallable)
    void OnRep_CreativeModeSettings();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnRep_CollectionRewardsUpdated();
    
public:
    UFUNCTION(BlueprintCallable)
    void OnAuthorityUnlockedItemsChanged(const TArray<TSubclassOf<UItemType>>& NewUnlockedItems);
    
    UFUNCTION(BlueprintCallable)
    void OnAuthorityResearchPointBalanceChanged(float NewPointBalance);
    
    UFUNCTION(BlueprintCallable)
    void OnAuthorityKnownItemsChanged(const TArray<TSubclassOf<UItemType>>& newKnownItems);
    
    UFUNCTION(BlueprintCallable)
    void OnAuthorityHackedItemsChanged(const TArray<TSubclassOf<UItemType>>& newHackedItems);
    
    UFUNCTION(BlueprintCallable)
    bool NotifyTutorial(FName Name, bool bShowText);
    
protected:
    UFUNCTION(BlueprintCallable)
    void NotifyOutroCinematicCompleted();
    
public:
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void MultiSoundFX(const FTransform& Transform, USoundBase* Sound, UParticleSystem* Particle);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastSyncSettingsFromServer(bool IsCustomGame, const FAstroCustomGameSettings& CustomGameSettings, const FAstroCustomGameState& customGameStateToSync);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastSyncOneTimeTooltipStateFromServer(const FAstroOneTimeTooltipState& oneTimeTooltipStateToSync);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastSyncInitialCustomGameStateFromServer(const FAstroCustomGameState& customGameStateToSync);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastSyncCustomGameStateFromServer(const FAstroCustomGameState& customGameStateToSync);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastNewMaterialPalette(ASolarBody* SolarBody, const TArray<FPackedVoxelMaterialInfo>& dynamicMaterials, const FVector& InLocation);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastNewCreativeMaterialPalette(ASolarBody* SolarBody, const TArray<FPackedVoxelMaterialInfo>& dynamicMaterials, const TArray<FCreativePaintMaterialMapping>& creativePaintData, const FVector& InLocation);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void MulticastExplosionEffects(const FTransform& Transform, AActor* Actor, const FName surfTypeSwitchName, const TArray<FString>& AudioEffects, const TArray<UParticleSystem*>& ParticleEffects, float Power);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastDisplayResearchPointChange(int32 researchPointDelta);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastDisplayGrantDurableMessage(TSubclassOf<UItemType> itemToUnlock);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void MulticastAudioEventAndVFXWithTint(const FTransform& Transform, const FString& AudioEvent, UParticleSystem* ParticleEffect, FLinearColor Color);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void MulticastAudioEventAndVFX(const FTransform& Transform, const FString& AudioEvent, UParticleSystem* ParticleEffect);
    
    UFUNCTION(BlueprintCallable)
    bool IsRootKitInstalled(EPlanetIdentifier planetID, int32 StormID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsProbeUnlocked(AAstroCharacter* Character, FName ProbeName) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsOxygenFreeCreative() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInvisibleToHazardsCreative() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInvincibleCreative() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsGravitySimulationEnabled() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsFuelFreeCreative() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsDonationRewardActive(const EDonationReward inDonationReward) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsCreativeModeActive() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsCollectionRewardActive(const ECollectionReward inCollectionReward) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsCatalogUnlockedCreative() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsBackpackPowerUnlimitedCreative() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAchievementProgressionDisabled() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasSaveGameCacheBeenEnumerated() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasEverBeenIndividualDedicatedServerGame() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasEverBeenCreativeGame() const;
    
protected:
    UFUNCTION(BlueprintCallable)
    void HandleOnGameplayStartedEvent(bool StartedInExistingSavedGame);
    
public:
    UFUNCTION(BlueprintCallable)
    void GlitchWalkersFinalEncounterStart();
    
    UFUNCTION(BlueprintCallable)
    void GlitchWalkersFinalEncounterReset();
    
    UFUNCTION(BlueprintCallable)
    void GlitchWalkersFinalEncounterCompleted();
    
    UFUNCTION(BlueprintCallable)
    bool GetThemeIsActive(const FName ThemeName);
    
    UFUNCTION(BlueprintCallable)
    FStormState GetStormState(AAstroStorm* storm);
    
    UFUNCTION(BlueprintCallable)
    bool GetStormsMissionBlocked();
    
    UFUNCTION(BlueprintCallable)
    bool GetStormsEnabled();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<APhysicalItem*> GetStartingItemArrayRef();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    URewardSystem* GetRewardSystem() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    URewardState* GetRewardState() const;
    
    UFUNCTION(BlueprintCallable)
    bool GetPreventCompletedMissionPlacements() const;
    
    UFUNCTION(BlueprintCallable)
    FPlanetVirusProtectionKitState GetPlanetVirusProtectionKitState(EPlanetIdentifier planetID);
    
    UFUNCTION(BlueprintCallable)
    FStormStates GetPlanetStormStatesById(EPlanetIdentifier planetID);
    
    UFUNCTION(BlueprintCallable)
    FStormStates GetPlanetStormStates(AAstroPlanet* Planet);
    
    UFUNCTION(BlueprintCallable)
    FPlanetFirewallStates GetPlanetFirewallStates(EPlanetIdentifier planetID);
    
    UFUNCTION(BlueprintCallable)
    TArray<FStormState> GetPlanetActiveStormStates(EPlanetIdentifier planetID);
    
    UFUNCTION(BlueprintCallable)
    TArray<int32> GetPlanetActiveStormIDs(EPlanetIdentifier planetID);
    
    UFUNCTION(BlueprintCallable)
    UActorClassList* GetNonPersistantActorClassList();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FScannableStatus GetNearestRelevantScannable(AAstroCharacter* Player) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AAstroMissionsManager* GetMissionsManager() const;
    
    UFUNCTION(BlueprintCallable)
    TMap<FString, UActorClassList*> GetMissionPlacementClassLists();
    
    UFUNCTION(BlueprintCallable)
    UActorClassList* GetMissionPlacementClasses(const FString& missionId);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UMegastructureManager* GetMegastructureManager() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIsNewGameDropshipSequenceActive() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetInstalledRootKitCount() const;
    
    UFUNCTION(BlueprintCallable)
    TArray<UActorClassList*> GetInactiveLTEActorClassLists();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<TSubclassOf<UItemType>> GetHackedItemTypes() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AAstroCustomGameManager* GetCustomGameManager() const;
    
    UFUNCTION(BlueprintCallable)
    TSubclassOf<UItemType> GetCounterhackKeyItemTypeClass(EPlanetIdentifier planetID, int32 StormID);
    
    UFUNCTION(BlueprintCallable)
    TSubclassOf<APhysicalItem> GetCounterhackKeyActorClass(EPlanetIdentifier planetID, int32 StormID);
    
    UFUNCTION(BlueprintCallable)
    FStormState GetClosestActiveStormToLocation(EPlanetIdentifier planetID, FVector Location);
    
    UFUNCTION(BlueprintCallable)
    bool GetCanGenerateCounterhackKey(EPlanetIdentifier planetID, int32 StormID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UAstropediaAssetManager* GetAstropediaAssetManager() const;
    
    UFUNCTION(BlueprintCallable)
    TArray<FStormState> GetAllActiveStormStates();
    
    UFUNCTION(BlueprintCallable)
    TArray<int32> GetAllActiveStormIDs();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UActuatorQueue* GetActuatorQueue() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EAchievementProgressionState GetAchievementProgressionState() const;
    
    UFUNCTION(BlueprintCallable)
    void EnableEXOVaultByName(FName Name);
    
    UFUNCTION(BlueprintCallable)
    void DoDeformation(FDeformationParamsT2 params, bool shouldThrottle);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void DisplayDiscoverItemTypeMessage(TSubclassOf<UItemType> itemTypeDiscovered);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void DestroyAllSpawnedStartingItems();
    
protected:
    UFUNCTION(BlueprintCallable)
    void BroadcastUnlockedVintageProbesChanged();
    
public:
    UFUNCTION(BlueprintCallable)
    void BroadcastUnlockedItemsChanged();
    
    UFUNCTION(BlueprintCallable)
    void BroadcastResearchPointBalanceChanged();
    
    UFUNCTION(BlueprintCallable)
    void BroadcastOnCreativeModeCatalogUnlockedChanged();
    
    UFUNCTION(BlueprintCallable)
    void BroadcastKnownItemsChanged();
    
    UFUNCTION(BlueprintCallable)
    void BroadcastHackedItemsChanged();
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    bool AuthorityTrySubmitStormData(EPlanetIdentifier planetID, int32 StormID);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    bool AuthorityTrySubmitRootKit(EPlanetIdentifier planetID, int32 StormID);
    
    UFUNCTION(BlueprintCallable)
    void AuthoritySpawnFirewalls(AAstroPlanet* Planet);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthoritySetWandererRealityTearOpenState(EWandererRealityTearOpenState State);
    
    UFUNCTION(BlueprintCallable)
    bool AuthorityRemoveStormSpawnLocationCandidate(AAstroStormSpawnLocationCandidate* candidate);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityRegisterFirewall(EPlanetIdentifier planetID, AActor* FirewallActor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EWandererRealityTearOpenState AuthorityGetWandererRealityTearOpenState() const;
    
    UFUNCTION(BlueprintCallable)
    bool AuthorityAddStormSpawnLocationCandidate(AAstroStormSpawnLocationCandidate* candidate);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool ArePlayerNamesVisible() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool AreBeaconsVisible() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool AreAnyShuttlesLost() const;
    
    UFUNCTION(BlueprintCallable)
    void AddLostShuttle(AShuttle* InShuttle);
    
    UFUNCTION(BlueprintCallable)
    void AddAndPrioritizeNewPlayerSpawnLocation(AActor* Spawn);
    
    UFUNCTION(BlueprintCallable)
    void AddActivePlacementThemes(const TArray<FName>& themeNames);
    
    UFUNCTION(BlueprintCallable)
    void AddActivePlacementTheme(const FName ThemeName);
    
};

