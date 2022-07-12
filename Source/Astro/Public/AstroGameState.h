#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=GameState -FallbackName=GameState
#include "EnableSignalDelegate.h"
#include "OnItemTypeListChangedDelegate.h"
#include "TutorialSignalDelegate.h"
#include "StarterItemCreatedDelegate.h"
#include "SignalDelegate.h"
#include "OnCurrentResearchPointBalanceChangedDelegate.h"
#include "OutroSequenceActorCreatedDelegate.h"
#include "ProbeUnlockState.h"
#include "WanderRealityTearOpenStateEventDelegate.h"
#include "EAstroAchievementKeys.h"
#include "ItemCollectionAchievementProgress.h"
#include "ScannableStatus.h"
#include "ActiveTerrainColorChangedDelegate.h"
#include "DebugLocation.h"
#include "AstroRemotePlayerChunk.h"
#include "CreativePaintMaterialMapping.h"
#include "PackedVoxelMaterialInfo.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Transform -FallbackName=Transform
//CROSS-MODULE INCLUDE V2: -ModuleName=Terrain2 -ObjectName=PackedVoxelMaterialInfo -FallbackName=PackedVoxelMaterialInfo
//CROSS-MODULE INCLUDE V2: -ModuleName=Terrain2 -ObjectName=DeformationParamsT2 -FallbackName=DeformationParamsT2
//CROSS-MODULE INCLUDE V2: -ModuleName=Terrain2 -ObjectName=CreativePaintMaterialMapping -FallbackName=CreativePaintMaterialMapping
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=LinearColor -FallbackName=LinearColor
#include "EAchievementProgressionState.h"
#include "EWandererRealityTearOpenState.h"
#include "DeformationCompleteEventDelegate.h"
#include "GameFramework/GameState.h"
#include "AstroGameState.generated.h"

class URewardState;
class UActivation;
class APhysicalItem;
class UItemType;
class ULevelSequencePlayer;
class AActor;
class UActorEntityLinkComponent;
class ALevelSequenceActor;
class AAstroCharacter;
class UAstropediaAssetManager;
class UActuatorQueue;
class ARailNetwork;
class URewardSystem;
class AAstroMissionsManager;
class UAstroSaveCustomArchiveProxy;
class AAstroPlanet;
class USoundBase;
class UParticleSystem;

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
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, SaveGame, meta=(AllowPrivateAccess=true))
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
    
    UPROPERTY(EditAnywhere, Transient)
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
    UFUNCTION()
    void SaveGameSerializeCustom(UAstroSaveCustomArchiveProxy* proxy);
    
public:
    UFUNCTION(BlueprintCallable)
    void RemoveNewPlayerSpawnLocation(AActor* Spawn);
    
    UFUNCTION(BlueprintCallable)
    void RegisterSpawnedStartingItem(APhysicalItem* Item);
    
protected:
    UFUNCTION()
    void OnRep_RailNetwork(ARailNetwork* previousValue);
    
    UFUNCTION()
    void OnRep_MissionsManager(AAstroMissionsManager* previousValue);
    
    UFUNCTION()
    void OnRep_IsOutroCinematicActive();
    
    UFUNCTION()
    void OnRep_CreativeModeSettings();
    
public:
    UFUNCTION()
    void OnAuthorityUnlockedItemsChanged(const TArray<TSubclassOf<UItemType>>& NewUnlockedItems);
    
    UFUNCTION()
    void OnAuthorityResearchPointBalanceChanged(float NewPointBalance);
    
    UFUNCTION()
    void OnAuthorityKnownItemsChanged(const TArray<TSubclassOf<UItemType>>& newKnownItems);
    
    UFUNCTION(BlueprintCallable)
    bool NotifyTutorial(FName Name, bool bShowText);
    
protected:
    UFUNCTION()
    void NotifyOutroCinematicCompleted();
    
public:
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void MultiSoundFX(const FTransform& Transform, USoundBase* Sound, UParticleSystem* Particle);
    
    UFUNCTION(NetMulticast, Reliable)
    void MulticastNewMaterialPalette(AAstroPlanet* Planet, const TArray<FPackedVoxelMaterialInfo>& dynamicMaterials);
    
    UFUNCTION(NetMulticast, Reliable)
    void MulticastNewCreativeMaterialPalette(AAstroPlanet* Planet, const TArray<FPackedVoxelMaterialInfo>& dynamicMaterials, const TArray<FCreativePaintMaterialMapping>& creativePaintData);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void MulticastExplosionEffects(const FTransform& Transform, AActor* Actor, const FName surfTypeSwitchName, const TArray<FString>& AudioEffects, const TArray<UParticleSystem*>& ParticleEffects, float Power);
    
    UFUNCTION(NetMulticast, Reliable)
    void MulticastDisplayResearchPointChange(int32 researchPointDelta);
    
    UFUNCTION(NetMulticast, Reliable)
    void MulticastDisplayGrantDurableMessage(TSubclassOf<UItemType> itemToUnlock);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void MulticastAudioEventAndVFXWithTint(const FTransform& Transform, const FString& AudioEvent, UParticleSystem* ParticleEffect, FLinearColor Color);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void MulticastAudioEventAndVFX(const FTransform& Transform, const FString& AudioEvent, UParticleSystem* ParticleEffect);
    
    UFUNCTION(BlueprintPure)
    bool IsProbeUnlocked(AAstroCharacter* Character, FName ProbeName) const;
    
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
    TArray<APhysicalItem*> GetStartingItemArrayRef();
    
    UFUNCTION(BlueprintPure)
    URewardSystem* GetRewardSystem() const;
    
    UFUNCTION(BlueprintPure)
    URewardState* GetRewardState() const;
    
    UFUNCTION(BlueprintPure)
    FScannableStatus GetNearestRelevantScannable(AAstroCharacter* Player) const;
    
    UFUNCTION(BlueprintPure)
    AAstroMissionsManager* GetMissionsManager() const;
    
    UFUNCTION(BlueprintPure)
    bool GetIsNewGameDropshipSequenceActive() const;
    
    UFUNCTION(BlueprintPure)
    UAstropediaAssetManager* GetAstropediaAssetManager() const;
    
    UFUNCTION(BlueprintPure)
    UActuatorQueue* GetActuatorQueue() const;
    
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
    void AddAndPrioritizeNewPlayerSpawnLocation(AActor* Spawn);
    
};

