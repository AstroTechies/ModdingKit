#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "OnItemTypeListChangedDelegate.h"
#include "OnCurrentResearchPointBalanceChangedDelegate.h"
#include "GameFramework/GameState.h"
#include "TutorialSignalDelegate.h"
#include "ScannableStatus.h"
#include "OutroSequenceActorCreatedDelegate.h"
#include "StarterItemCreatedDelegate.h"
#include "SignalDelegate.h"
#include "EnableSignalDelegate.h"
#include "WanderRealityTearOpenStateEventDelegate.h"
#include "EAstroAchievementKeys.h"
#include "ItemCollectionAchievementProgress.h"
#include "ActiveTerrainColorChangedDelegate.h"
#include "ProbeUnlockState.h"
#include "DebugLocation.h"
#include "EWandererRealityTearOpenState.h"
#include "UObject/NoExportTypes.h"
#include "CreativePaintMaterialMapping.h"
#include "AstroRemotePlayerChunk.h"
#include "UObject/NoExportTypes.h"
#include "PackedVoxelMaterialInfo.h"
#include "EAchievementProgressionState.h"
#include "DeformationParamsT2.h"
#include "DeformationCompleteEventDelegate.h"
#include "AstroGameState.generated.h"

class UItemType;
class USoundBase;
class UActivation;
class APhysicalItem;
class UActorEntityLinkComponent;
class AActor;
class ULevelSequencePlayer;
class ALevelSequenceActor;
class UAstropediaAssetManager;
class UActuatorQueue;
class URewardState;
class ARailNetwork;
class URewardSystem;
class AAstroMissionsManager;
class UAstroSaveCustomArchiveProxy;
class UParticleSystem;
class AAstroPlanet;
class AAstroCharacter;

UCLASS(Blueprintable, Blueprintable)
class AAstroGameState : public AGameState
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Replicated, meta = (AllowPrivateAccess = true))
    float GameSpeed;

    UPROPERTY(BlueprintReadWrite, Replicated, SaveGame, meta = (AllowPrivateAccess = true))
    float SolarTimeScaleMultiplierCreative;

    UPROPERTY(BlueprintAssignable)
    FTutorialSignal OnObjectiveSet;

    UPROPERTY(BlueprintAssignable)
    FTutorialSignal OnTutorialNotify;

    UPROPERTY(BlueprintAssignable, BlueprintCallable)
    FStarterItemCreated OnStarterItemCreated;

    UPROPERTY(BlueprintAssignable)
    FOnCurrentResearchPointBalanceChanged OnResearchPointBalanceChanged;

    UPROPERTY(BlueprintAssignable)
    FOnItemTypeListChanged OnKnownItemTypesChanged;

    UPROPERTY(BlueprintAssignable)
    FOnItemTypeListChanged OnUnlockedItemTypesChanged;

    UPROPERTY(BlueprintAssignable)
    FSignal OnCreativeModeCatalogUnlockedChanged;

    UPROPERTY(BlueprintAssignable)
    FEnableSignal OnCreativeModeEnabledChanged;

    UPROPERTY(BlueprintAssignable)
    FSignal OnAchievementProgressionDisabledChanged;

    UPROPERTY(BlueprintAssignable)
    FEnableSignal OnCreativeFreeFuelChanged;

    UPROPERTY(BlueprintAssignable)
    FSignal OnOutroCinematicStarted;

    UPROPERTY(BlueprintAssignable)
    FOutroSequenceActorCreated OnOutroSequenceActorCreated;

    UPROPERTY(BlueprintAssignable)
    FSignal OnOutroCinematicCompleted;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    UActivation *DeformToolActivation;

    UPROPERTY(BlueprintReadWrite, SaveGame, meta = (AllowPrivateAccess = true))
    TArray<TSubclassOf<APhysicalItem>> AvailableRecipes;

    UPROPERTY(BlueprintReadWrite, Replicated, SaveGame, meta = (AllowPrivateAccess = true))
    bool TutorialInteractionMode;

    UPROPERTY(BlueprintReadWrite, SaveGame, meta = (AllowPrivateAccess = true))
    bool TutorialSlowMovement;

    UPROPERTY(BlueprintReadWrite, SaveGame, meta = (AllowPrivateAccess = true))
    FName CurrentObjective;

    UPROPERTY(BlueprintReadWrite, SaveGame, meta = (AllowPrivateAccess = true))
    TArray<FName> TutorialNotifiedList;

    UPROPERTY(BlueprintReadWrite, SaveGame, meta = (AllowPrivateAccess = true))
    TArray<APhysicalItem *> SpawnedStartingItems;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    bool MapLoadedFromSave;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    bool SaveGamePermitted;

    UPROPERTY(BlueprintReadWrite, SaveGame, meta = (AllowPrivateAccess = true))
    float WindValue;

    UPROPERTY(BlueprintAssignable)
    FSignal OnMissionsManagerCreated;

    UPROPERTY(BlueprintAssignable)
    FSignal UnlockedVintageProbesChanged;

    UPROPERTY(BlueprintAssignable)
    FWanderRealityTearOpenStateEvent OnWandererRealityTearOpenChanged;

    UPROPERTY(SaveGame)
    TMap<EAstroAchievementKeys, int32> CountAchievementProgress;

    UPROPERTY(SaveGame)
    TMap<EAstroAchievementKeys, float> FloatAchievementProgress;

    UPROPERTY(SaveGame)
    TMap<EAstroAchievementKeys, FItemCollectionAchievementProgress> CollectionAchievementProgress;

    UPROPERTY(BlueprintAssignable)
    FActiveTerrainColorChanged OnActiveCreativeTerrainColorChanged;

protected:
    UPROPERTY(SaveGame)
    uint8 bIsMultiplayerEnabled : 1;

    UPROPERTY(Transient, ReplicatedUsing = OnRep_IsOutroCinematicActive)
    uint8 bIsOutroCinematicActive : 1;

    UPROPERTY(SaveGame)
    TArray<AActor *> NewPlayerSpawnLocations;

    UPROPERTY(SaveGame)
    TArray<AActor *> SpawnLocations;

    UPROPERTY(BlueprintReadWrite, Export, SaveGame, VisibleAnywhere, meta = (AllowPrivateAccess = true))
    UActorEntityLinkComponent *EntityLinkComponent;

    UPROPERTY(BlueprintReadWrite, Transient, ReplicatedUsing = BroadcastResearchPointBalanceChanged, meta = (AllowPrivateAccess = true))
    float CurrentResearchPointBalance;

    UPROPERTY(BlueprintReadWrite, Replicated, Transient, meta = (AllowPrivateAccess = true))
    float CurrentResearchPointsPerMinute;

    UPROPERTY(BlueprintReadWrite, Transient, ReplicatedUsing = BroadcastKnownItemsChanged, meta = (AllowPrivateAccess = true))
    TArray<TSubclassOf<UItemType>> KnownItemTypes;

    UPROPERTY(BlueprintReadWrite, Transient, ReplicatedUsing = BroadcastUnlockedItemsChanged, meta = (AllowPrivateAccess = true))
    TArray<TSubclassOf<UItemType>> UnlockedItemTypes;

    UPROPERTY(Replicated)
    TArray<FScannableStatus> ScannableStatuses;

    UPROPERTY(SaveGame, ReplicatedUsing = BroadcastUnlockedVintageProbesChanged)
    TArray<FProbeUnlockState> ProbeUnlockStates;

private:
    UPROPERTY(Transient)
    ULevelSequencePlayer *OutroCinematicPlayer;

    UPROPERTY(Transient)
    ALevelSequenceActor *OutroSequenceActor;

    UPROPERTY(Replicated, SaveGame)
    TArray<FDebugLocation> DebugLocations;

    UPROPERTY(SaveGame, ReplicatedUsing = OnRep_CreativeModeSettings)
    uint8 bAchievementProgressionDisabled : 1;

    UPROPERTY(SaveGame, ReplicatedUsing = OnRep_CreativeModeSettings)
    uint8 bIsIndividualDedicatedServerGame : 1;

    UPROPERTY(SaveGame, ReplicatedUsing = OnRep_CreativeModeSettings)
    uint8 bCreativeModeActive : 1;

    UPROPERTY(SaveGame, ReplicatedUsing = OnRep_CreativeModeSettings)
    uint8 bCreativeAllCatalogItemsUnlocked : 1;

    UPROPERTY(SaveGame)
    uint8 bCreativeFreeOxygenOn : 1;

    UPROPERTY(SaveGame, ReplicatedUsing = OnRep_CreativeModeSettings)
    uint8 bCreativeFreeFuelOn : 1;

    UPROPERTY(SaveGame)
    uint8 bCreativeInvisibleToHazardsOn : 1;

    UPROPERTY(SaveGame)
    uint8 bCreativeInvincibleOn : 1;

    UPROPERTY(SaveGame)
    uint8 bCreativeUnlimitedBackpackPowerOn : 1;

    UPROPERTY(Transient)
    float MatCollectionGameSpeed;

    UPROPERTY()
    UAstropediaAssetManager *AstropediaAssetManager;

    UPROPERTY(SaveGame)
    UActuatorQueue *ActuatorQueue;

    UPROPERTY(SaveGame, ReplicatedUsing = OnRep_RailNetwork)
    ARailNetwork *RailNetwork;

    UPROPERTY(Transient)
    URewardSystem *RewardSystem;

    UPROPERTY(Transient)
    URewardState *RewardState;

    UPROPERTY(SaveGame, ReplicatedUsing = OnRep_MissionsManager)
    AAstroMissionsManager *MissionsManager;

    UPROPERTY(Transient)
    TArray<FAstroRemotePlayerChunk> RemotePlayerHistory;

    UPROPERTY(Transient)
    TMap<uint16, FDeformationCompleteEvent> DeformationCompleteEvents;

public:
    AAstroGameState();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    void UnregisterSpawnedStartingItem(APhysicalItem *Item);

    UFUNCTION(BlueprintCallable)
    void SetOxygenFreeCreative(bool OxygenFree);

    UFUNCTION(BlueprintCallable)
    void SetNewGameDropshipSequenceActive(bool IsActive);

    UFUNCTION(BlueprintCallable)
    void SetInvisibleToHazardsCreative(bool InvisibleToHazards);

    UFUNCTION(BlueprintCallable)
    void SetInvincibleCreative(bool Invincible);

    UFUNCTION(BlueprintCallable)
    void SetFuelFreeCreative(bool FreeFuelEnabled);

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

protected:
    UFUNCTION()
    void SaveGameSerializeCustom(UAstroSaveCustomArchiveProxy *proxy);

public:
    UFUNCTION(BlueprintCallable)
    void RemoveNewPlayerSpawnLocation(AActor *Spawn);

    UFUNCTION(BlueprintCallable)
    void RegisterSpawnedStartingItem(APhysicalItem *Item);

protected:
    UFUNCTION()
    void OnRep_RailNetwork(ARailNetwork *previousValue);

    UFUNCTION()
    void OnRep_MissionsManager(AAstroMissionsManager *previousValue);

    UFUNCTION()
    void OnRep_IsOutroCinematicActive();

    UFUNCTION()
    void OnRep_CreativeModeSettings();

public:
    UFUNCTION()
    void OnAuthorityUnlockedItemsChanged(const TArray<TSubclassOf<UItemType>> &NewUnlockedItems);

    UFUNCTION()
    void OnAuthorityResearchPointBalanceChanged(float NewPointBalance);

    UFUNCTION()
    void OnAuthorityKnownItemsChanged(const TArray<TSubclassOf<UItemType>> &newKnownItems);

    UFUNCTION(BlueprintCallable)
    bool NotifyTutorial(FName Name, bool bShowText);

protected:
    UFUNCTION()
    void NotifyOutroCinematicCompleted();

public:
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void MultiSoundFX(const FTransform &Transform, USoundBase *Sound, UParticleSystem *Particle);

    UFUNCTION(NetMulticast, Reliable)
    void MulticastNewMaterialPalette(AAstroPlanet *Planet, const TArray<FPackedVoxelMaterialInfo> &dynamicMaterials);

    UFUNCTION(NetMulticast, Reliable)
    void MulticastNewCreativeMaterialPalette(AAstroPlanet *Planet, const TArray<FPackedVoxelMaterialInfo> &dynamicMaterials, const TArray<FCreativePaintMaterialMapping> &creativePaintData);

    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void MulticastExplosionEffects(const FTransform &Transform, AActor *Actor, const FName surfTypeSwitchName, const TArray<FString> &AudioEffects, const TArray<UParticleSystem *> &ParticleEffects, float Power);

    UFUNCTION(NetMulticast, Reliable)
    void MulticastDisplayResearchPointChange(int32 researchPointDelta);

    UFUNCTION(NetMulticast, Reliable)
    void MulticastDisplayGrantDurableMessage(TSubclassOf<UItemType> itemToUnlock);

    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void MulticastAudioEventAndVFXWithTint(const FTransform &Transform, const FString &AudioEvent, UParticleSystem *ParticleEffect, FLinearColor Color);

    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void MulticastAudioEventAndVFX(const FTransform &Transform, const FString &AudioEvent, UParticleSystem *ParticleEffect);

    UFUNCTION(BlueprintPure)
    bool IsProbeUnlocked(AAstroCharacter *Character, FName ProbeName) const;

    UFUNCTION(BlueprintPure)
    bool IsOxygenFreeCreative() const;

    UFUNCTION(BlueprintPure)
    bool IsInvisibleToHazardsCreative() const;

    UFUNCTION(BlueprintPure)
    bool IsInvincibleCreative() const;

    UFUNCTION(BlueprintPure)
    bool IsGravitySimulationEnabled() const;

    UFUNCTION(BlueprintPure)
    bool IsFuelFreeCreative() const;

    UFUNCTION(BlueprintPure)
    bool IsCreativeModeActive() const;

    UFUNCTION(BlueprintPure)
    bool IsCatalogUnlockedCreative() const;

    UFUNCTION(BlueprintPure)
    bool IsBackpackPowerUnlimitedCreative() const;

    UFUNCTION(BlueprintPure)
    bool IsAchievementProgressionDisabled() const;

    UFUNCTION(BlueprintPure)
    bool HasSaveGameCacheBeenEnumerated() const;

    UFUNCTION(BlueprintPure)
    bool HasEverBeenIndividualDedicatedServerGame() const;

    UFUNCTION(BlueprintPure)
    bool HasEverBeenCreativeGame() const;

protected:
    UFUNCTION()
    void HandleOnGameplayStartedEvent(bool StartedInExistingSavedGame);

public:
    UFUNCTION(BlueprintPure)
    TArray<APhysicalItem *> GetStartingItemArrayRef();

    UFUNCTION(BlueprintPure)
    URewardSystem *GetRewardSystem() const;

    UFUNCTION(BlueprintPure)
    URewardState *GetRewardState() const;

    UFUNCTION(BlueprintPure)
    FScannableStatus GetNearestRelevantScannable(AAstroCharacter *Player) const;

    UFUNCTION(BlueprintPure)
    AAstroMissionsManager *GetMissionsManager() const;

    UFUNCTION(BlueprintPure)
    bool GetIsNewGameDropshipSequenceActive() const;

    UFUNCTION(BlueprintPure)
    UAstropediaAssetManager *GetAstropediaAssetManager() const;

    UFUNCTION(BlueprintPure)
    UActuatorQueue *GetActuatorQueue() const;

    UFUNCTION(BlueprintPure)
    EAchievementProgressionState GetAchievementProgressionState() const;

    UFUNCTION(BlueprintCallable)
    void DoDeformation(FDeformationParamsT2 params, bool shouldThrottle);

    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void DisplayDiscoverItemTypeMessage(TSubclassOf<UItemType> itemTypeDiscovered);

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void DestroyAllSpawnedStartingItems();

protected:
    UFUNCTION()
    void BroadcastUnlockedVintageProbesChanged();

public:
    UFUNCTION()
    void BroadcastUnlockedItemsChanged();

    UFUNCTION()
    void BroadcastResearchPointBalanceChanged();

    UFUNCTION()
    void BroadcastOnCreativeModeCatalogUnlockedChanged();

    UFUNCTION()
    void BroadcastKnownItemsChanged();

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthoritySetWandererRealityTearOpenState(EWandererRealityTearOpenState State);

    UFUNCTION(BlueprintPure)
    EWandererRealityTearOpenState AuthorityGetWandererRealityTearOpenState() const;

    UFUNCTION(BlueprintPure)
    bool ArePlayerNamesVisible() const;

    UFUNCTION(BlueprintPure)
    bool AreBeaconsVisible() const;

    UFUNCTION(BlueprintCallable)
    void AddAndPrioritizeNewPlayerSpawnLocation(AActor *Spawn);
};
