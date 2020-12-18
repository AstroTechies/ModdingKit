// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameState.h"
#include "LevelSequencePlayer.h"
#include "Particles/ParticleSystem.h" 
#include "Items/ItemType.h"
#include "Items/PhysicalItem.h"
#include "Utilities/ActivationSignals.h"
#include "AstroGameState.generated.h"

UCLASS(BlueprintType)
class ASTRO_API AAstroGameState : public AGameState
{
	GENERATED_BODY()

public:
	/*UFUNCTION(BlueprintCallable)
		void DoDeformation(FDeformationParamsT2* params, bool ShouldThrottle);
	UFUNCTION(BlueprintCallable)
		void MulticastNewMaterialPalette(AAstroPlanet* planet, TArray<FPackedVoxelMaterialInfo> dynamicMaterials);
	UFUNCTION(BlueprintCallable)
		void MulticastNewCreativeMaterialPalette(AAstroPlanet* planet, TArray<FPackedVoxelMaterialInfo> dynamicMaterials, TArray<FCreativePaintMaterialMapping> creativePaintData);*/
	UFUNCTION(BlueprintCallable)
		void SetCurrentObjective(FName Name);
	UFUNCTION(BlueprintCallable)
		bool NotifyTutorial(FName Name, bool bShowText);
	UFUNCTION(BlueprintCallable)
		void MulticastAudioEventAndVFXWithTint(FTransform Transform, FString AudioEvent, UParticleSystem* ParticleEffect, FLinearColor Color);
	UFUNCTION(BlueprintCallable)
		void MulticastExplosionEffects(FTransform Transform, AActor* actor, FName surfTypeSwitchName, TArray<FString> AudioEffects, TArray<UParticleSystem*> ParticleEffects, float Power);
	/*UFUNCTION(BlueprintCallable)
		UActuatorQueue* GetActuatorQueue();
	UFUNCTION(BlueprintCallable)
		URewardSystem* GetRewardSystem();
	UFUNCTION(BlueprintCallable)
		URewardState* GetRewardState();*/
	UFUNCTION(BlueprintCallable)
		void DisplayDiscoverItemTypeMessage(TSubclassOf<UItemType> itemTypeDiscovered);
	UFUNCTION(BlueprintCallable)
		void MulticastDisplayGrantDurableMessage(TSubclassOf<UItemType> itemToUnlock);
	UFUNCTION(BlueprintCallable)
		void MulticastDisplayResearchPointChange(int researchPointDelta);
	UFUNCTION(BlueprintCallable, BlueprintPure)
		bool IsGravitySimulationEnabled();
	UFUNCTION(BlueprintCallable, BlueprintPure)
		bool AreBeaconsVisible();
	UFUNCTION(BlueprintCallable, BlueprintPure)
		bool ArePlayerNamesVisible();
	UFUNCTION(BlueprintCallable, BlueprintPure)
		bool HasSaveGameCacheBeenEnumerated();
	UFUNCTION(BlueprintCallable)
		void AddAndPrioritizeNewPlayerSpawnLocation(AActor* spawn);
	UFUNCTION(BlueprintCallable)
		void RemoveNewPlayerSpawnLocation(AActor* spawn);
	UFUNCTION(BlueprintCallable)
		void DestroyAllSpawnedStartingItems();
	UFUNCTION(BlueprintCallable)
		void RegisterSpawnedStartingItem(APhysicalItem* item);
	UFUNCTION(BlueprintCallable)
		void UnregisterSpawnedStartingItem(APhysicalItem* item);
	UFUNCTION(BlueprintCallable)
		TArray<APhysicalItem*> GetStartingItemArrayRef();
	/*UFUNCTION(BlueprintCallable)
		bool IsProbeUnlocked(AAstroCharacter* character, FName ProbeName);*/
	/*UFUNCTION(BlueprintCallable)
		void AuthoritySetWandererRealityTearOpenState(EWandererRealityTearOpenState state);
	UFUNCTION(BlueprintCallable)
		EWandererRealityTearOpenState AuthorityGetWandererRealityTearOpenState();
	UFUNCTION(BlueprintCallable)
		FScannableStatus GetNearestRelevantScannable(AAstroCharacter* player);*/
	UFUNCTION(BlueprintCallable)
		void OnAuthorityResearchPointBalanceChanged(float NewPointBalance);
	UFUNCTION(BlueprintCallable)
		void OnAuthorityKnownItemsChanged(TArray<TSubclassOf<UItemType>> newKnownItems);
	UFUNCTION(BlueprintCallable)
		void OnAuthorityUnlockedItemsChanged(TArray<TSubclassOf<UItemType>> NewUnlockedItems);
	UFUNCTION(BlueprintCallable)
		void BroadcastResearchPointBalanceChanged();
	UFUNCTION(BlueprintCallable)
		void BroadcastKnownItemsChanged();
	UFUNCTION(BlueprintCallable)
		void BroadcastUnlockedItemsChanged();
	UFUNCTION(BlueprintCallable)
		void BroadcastOnCreativeModeCatalogUnlockedChanged();
	UFUNCTION(BlueprintCallable, BlueprintPure)
		bool IsCreativeModeActive();
	UFUNCTION(BlueprintCallable)
		void SetCreativeModeActive(bool creativeModeActive);
	UFUNCTION(BlueprintCallable, BlueprintPure)
		bool IsFuelFreeCreative();
	UFUNCTION(BlueprintCallable)
		void SetFuelFreeCreative(bool freeFuelEnabled);
	UFUNCTION(BlueprintCallable, BlueprintPure)
		bool IsCatalogUnlockedCreative();
	UFUNCTION(BlueprintCallable)
		void SetCatalogUnlockedCreative(bool catalogUnlocked);
	UFUNCTION(BlueprintCallable, BlueprintPure)
		bool IsOxygenFreeCreative();
	UFUNCTION(BlueprintCallable)
		void SetOxygenFreeCreative(bool oxygenFree);
	UFUNCTION(BlueprintCallable, BlueprintPure)
		bool IsInvincibleCreative();
	UFUNCTION(BlueprintCallable)
		void SetInvincibleCreative(bool invincible);
	UFUNCTION(BlueprintCallable, BlueprintPure)
		bool IsInvisibleToHazardsCreative();
	UFUNCTION(BlueprintCallable)
		void SetInvisibleToHazardsCreative(bool invisibleToHazards);
	UFUNCTION(BlueprintCallable, BlueprintPure)
		bool IsBackpackPowerUnlimitedCreative();
	UFUNCTION(BlueprintCallable)
		void SetBackpackPowerUnlimitedCreative(bool backpackPowerUnlimited);
	UFUNCTION(BlueprintCallable, BlueprintPure)
		bool IsAchievementProgressionDisabled();
	UFUNCTION(BlueprintCallable, BlueprintPure)
		bool HasEverBeenCreativeGame();
	UFUNCTION(BlueprintCallable, BlueprintPure)
		bool HasEverBeenIndividualDedicatedServerGame();
	/*UFUNCTION(BlueprintCallable)
		EAchievementProgressionState GetAchievementProgressionState();*/
	UFUNCTION(BlueprintCallable)
		void SetAchievementProgressionDisabledCreative(bool achievementProgressionDisabled);
	UFUNCTION(BlueprintCallable)
		void SetNewGameDropshipSequenceActive(bool isActive);
	UFUNCTION(BlueprintCallable, BlueprintPure)
		bool GetIsNewGameDropshipSequenceActive();
	/*UFUNCTION(BlueprintCallable)
		void SaveGameSerializeCustom(UAstroSaveCustomArchiveProxy* proxy);*/
	UFUNCTION(BlueprintCallable)
		void NotifyOutroCinematicCompleted();
	UFUNCTION(BlueprintCallable)
		void OnRep_CreativeModeSettings();
	UFUNCTION(BlueprintCallable)
		void OnRep_IsOutroCinematicActive();
	UFUNCTION(BlueprintCallable)
		void BroadcastUnlockedVintageProbesChanged();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float GameSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float SolarTimeScaleMultiplierCreative;
	UPROPERTY(EditAnywhere, BlueprintAssignable, BlueprintReadWrite)
		FTutorialSignal OnObjectiveSet;
	UPROPERTY(EditAnywhere, BlueprintAssignable, BlueprintReadWrite)
		FTutorialSignal OnTutorialNotify;
	UPROPERTY(EditAnywhere, BlueprintAssignable, BlueprintReadWrite)
		FStarterItemCreated OnStarterItemCreated;
	UPROPERTY(EditAnywhere, BlueprintAssignable, BlueprintReadWrite)
		FOnCurrentResearchPointBalanceChanged OnResearchPointBalanceChanged;
	UPROPERTY(EditAnywhere, BlueprintAssignable, BlueprintReadWrite)
		FOnItemTypeListChanged OnKnownItemTypesChanged;
	UPROPERTY(EditAnywhere, BlueprintAssignable, BlueprintReadWrite)
		FOnItemTypeListChanged OnUnlockedItemTypesChanged;
	UPROPERTY(EditAnywhere, BlueprintAssignable, BlueprintReadWrite)
		FSignal OnCreativeModeCatalogUnlockedChanged;
	UPROPERTY(EditAnywhere, BlueprintAssignable, BlueprintReadWrite)
		FEnableSignal OnCreativeModeEnabledChanged;
	UPROPERTY(EditAnywhere, BlueprintAssignable, BlueprintReadWrite)
		FSignal OnAchievementProgressionDisabledChanged;
	UPROPERTY(EditAnywhere, BlueprintAssignable, BlueprintReadWrite)
		FEnableSignal OnCreativeFreeFuelChanged;
	UPROPERTY(EditAnywhere, BlueprintAssignable, BlueprintReadWrite)
		FSignal OnOutroCinematicStarted;
	UPROPERTY(EditAnywhere, BlueprintAssignable, BlueprintReadWrite)
		FOutroSequenceActorCreated OnOutroSequenceActorCreated;
	UPROPERTY(EditAnywhere, BlueprintAssignable, BlueprintReadWrite)
		FSignal OnOutroCinematicCompleted;
	/*UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UActivation* DeformToolActivation;*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<TSubclassOf<APhysicalItem>> AvailableRecipes;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool TutorialInteractionMode;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool TutorialSlowMovement;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName CurrentObjective;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FName> TutorialNotifiedList;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<APhysicalItem *> SpawnedStartingItems;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool MapLoadedFromSave;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool SaveGamePermitted;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float WindValue;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FSignal UnlockedVintageProbesChanged;
	/*UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FWanderRealityTearOpenStateEvent OnWandererRealityTearOpenChanged;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TMap<enum EAstroAchievementKeys,int,FDefaultSetAllocator,TDefaultMapHashableKeyFuncs<enum EAstroAchievementKeys,int,0> > CountAchievementProgress;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TMap<enum EAstroAchievementKeys,float,FDefaultSetAllocator,TDefaultMapHashableKeyFuncs<enum EAstroAchievementKeys,float,0> > FloatAchievementProgress;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TMap<enum EAstroAchievementKeys,FItemCollectionAchievementProgress,FDefaultSetAllocator,TDefaultMapHashableKeyFuncs<enum EAstroAchievementKeys,FItemCollectionAchievementProgress,0> > CollectionAchievementProgress;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FActiveTerrainColorChanged OnActiveCreativeTerrainColorChanged;*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<AActor *> NewPlayerSpawnLocations;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<AActor *> SpawnLocations;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UActorEntityLinkComponent* EntityLinkComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float CurrentResearchPointBalance;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float CurrentResearchPointsPerMinute;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<TSubclassOf<UItemType>> KnownItemTypes;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<TSubclassOf<UItemType>> UnlockedItemTypes;
	/*UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FScannableStatus> ScannableStatuses;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FProbeUnlockState> ProbeUnlockStates;*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		ULevelSequencePlayer* OutroCinematicPlayer;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		ALevelSequenceActor* OutroSequenceActor;
	/*UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FDebugLocation> DebugLocations;*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MatCollectionGameSpeed;
	/*UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UActuatorQueue* ActuatorQueue;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		URewardSystem* RewardSystem;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		URewardState* RewardState;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FAstroRemotePlayerChunk> RemotePlayerHistory;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TMap<unsigned short,FDeformationCompleteEvent,FDefaultSetAllocator,TDefaultMapHashableKeyFuncs<unsigned short,FDeformationCompleteEvent,0> > DeformationCompleteEvents;*/
};