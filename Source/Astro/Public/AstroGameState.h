#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=LinearColor -FallbackName=LinearColor
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Transform -FallbackName=Transform
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=GameState -FallbackName=GameState
//CROSS-MODULE INCLUDE V2: -ModuleName=Terrain2 -ObjectName=CreativePaintMaterialMapping -FallbackName=CreativePaintMaterialMapping
#include "DeformationParamsT2.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Terrain2 -ObjectName=PackedVoxelMaterialInfo -FallbackName=PackedVoxelMaterialInfo
#include "ActiveTerrainColorChangedDelegate.h"
#include "CreativePaintMaterialMapping.h"
#include "GameFramework/GameState.h"
#include "AstroRemotePlayerChunk.h"
#include "DebugLocation.h"
#include "EAchievementProgressionState.h"
#include "EAstroAchievementKeys.h"
#include "DeformationCompleteEventDelegate.h"
#include "EWandererRealityTearOpenState.h"
#include "EnableSignalDelegate.h"
#include "ItemCollectionAchievementProgress.h"
#include "OnCurrentResearchPointBalanceChangedDelegate.h"
#include "OnItemTypeListChangedDelegate.h"
#include "OutroSequenceActorCreatedDelegate.h"
#include "ProbeUnlockState.h"
#include "ScannableStatus.h"
#include "SignalDelegate.h"
#include "StarterItemCreatedDelegate.h"
#include "Templates/SubclassOf.h"
#include "PackedVoxelMaterialInfo.h"
#include "TutorialSignalDelegate.h"
#include "WanderRealityTearOpenStateEventDelegate.h"
#include "AstroGameState.generated.h"

class AActor;
class AAstroCharacter;
class AAstroMissionsManager;
class AAstroPlanet;
class ALevelSequenceActor;
class APhysicalItem;
class ARailNetwork;
class UActivation;
class UActorEntityLinkComponent;
class UActuatorQueue;
class UAstroSaveCustomArchiveProxy;
class UAstropediaAssetManager;
class UItemType;
class ULevelSequencePlayer;
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
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnMissionsManagerCreated;
    
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
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    URewardSystem* RewardSystem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    URewardState* RewardState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_MissionsManager, meta=(AllowPrivateAccess=true))
    AAstroMissionsManager* MissionsManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FAstroRemotePlayerChunk> RemotePlayerHistory;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<uint16, FDeformationCompleteEvent> DeformationCompleteEvents;
    
public:
    AAstroGameState();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION(BlueprintCallable)
    void UnregisterSpawnedStartingItem(APhysicalItem* Item);
    
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
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnRep_RailNetwork(ARailNetwork* previousValue);
    
    UFUNCTION(BlueprintCallable)
    void OnRep_MissionsManager(AAstroMissionsManager* previousValue);
    
    UFUNCTION(BlueprintCallable)
    void OnRep_IsOutroCinematicActive();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_CreativeModeSettings();
    
public:
    UFUNCTION(BlueprintCallable)
    void OnAuthorityUnlockedItemsChanged(const TArray<TSubclassOf<UItemType>>& NewUnlockedItems);
    
    UFUNCTION(BlueprintCallable)
    void OnAuthorityResearchPointBalanceChanged(float NewPointBalance);
    
    UFUNCTION(BlueprintCallable)
    void OnAuthorityKnownItemsChanged(const TArray<TSubclassOf<UItemType>>& newKnownItems);
    
    UFUNCTION(BlueprintCallable)
    bool NotifyTutorial(FName Name, bool bShowText);
    
protected:
    UFUNCTION(BlueprintCallable)
    void NotifyOutroCinematicCompleted();
    
public:
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void MultiSoundFX(const FTransform& Transform, USoundBase* Sound, UParticleSystem* Particle);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastNewMaterialPalette(AAstroPlanet* Planet, const TArray<FPackedVoxelMaterialInfo>& dynamicMaterials);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastNewCreativeMaterialPalette(AAstroPlanet* Planet, const TArray<FPackedVoxelMaterialInfo>& dynamicMaterials, const TArray<FCreativePaintMaterialMapping>& creativePaintData);
    
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
    bool IsCreativeModeActive() const;
    
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
    bool GetThemeIsActive(const FName ThemeName);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<APhysicalItem*> GetStartingItemArrayRef();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    URewardSystem* GetRewardSystem() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    URewardState* GetRewardState() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FScannableStatus GetNearestRelevantScannable(AAstroCharacter* Player) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AAstroMissionsManager* GetMissionsManager() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIsNewGameDropshipSequenceActive() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UAstropediaAssetManager* GetAstropediaAssetManager() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UActuatorQueue* GetActuatorQueue() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EAchievementProgressionState GetAchievementProgressionState() const;
    
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
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthoritySetWandererRealityTearOpenState(EWandererRealityTearOpenState State);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EWandererRealityTearOpenState AuthorityGetWandererRealityTearOpenState() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool ArePlayerNamesVisible() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool AreBeaconsVisible() const;
    
    UFUNCTION(BlueprintCallable)
    void AddAndPrioritizeNewPlayerSpawnLocation(AActor* Spawn);
    
    UFUNCTION(BlueprintCallable)
    void AddActivePlacementThemes(const TArray<FName>& themeNames);
    
    UFUNCTION(BlueprintCallable)
    void AddActivePlacementTheme(const FName ThemeName);
    
};

