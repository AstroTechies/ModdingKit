// Fill out your copyright notice in the Description page of Project Settings.

#include "AstroGameState.h"


/*void AAstroGameState::DoDeformation(FDeformationParamsT2* params, bool ShouldThrottle)
{

}

void AAstroGameState::MulticastNewMaterialPalette(AAstroPlanet* planet, TArray<FPackedVoxelMaterialInfo> dynamicMaterials)
{

}

void AAstroGameState::MulticastNewCreativeMaterialPalette(AAstroPlanet* planet, TArray<FPackedVoxelMaterialInfo> dynamicMaterials, TArray<FCreativePaintMaterialMapping> creativePaintData)
{

}*/

void AAstroGameState::SetCurrentObjective(FName Name)
{

}

bool AAstroGameState::NotifyTutorial(FName Name, bool bShowText)
{
	return false;
}

void AAstroGameState::MulticastAudioEventAndVFXWithTint(FTransform Transform, FString AudioEvent, UParticleSystem* ParticleEffect, FLinearColor Color)
{

}

void AAstroGameState::MulticastExplosionEffects(FTransform Transform, AActor* actor, FName surfTypeSwitchName, TArray<FString> AudioEffects, TArray<UParticleSystem *> ParticleEffects, float Power)
{

}

/*UActuatorQueue* AAstroGameState::GetActuatorQueue()
{
	return nullptr;
}

URewardSystem* AAstroGameState::GetRewardSystem()
{
	return nullptr;
}

URewardState* AAstroGameState::GetRewardState()
{
	return nullptr;
}*/

void AAstroGameState::DisplayDiscoverItemTypeMessage(TSubclassOf<UItemType> itemTypeDiscovered)
{

}

void AAstroGameState::MulticastDisplayGrantDurableMessage(TSubclassOf<UItemType> itemToUnlock)
{

}

void AAstroGameState::MulticastDisplayResearchPointChange(int researchPointDelta)
{

}

bool AAstroGameState::IsGravitySimulationEnabled()
{
	return false;
}

bool AAstroGameState::AreBeaconsVisible()
{
	return false;
}

bool AAstroGameState::ArePlayerNamesVisible()
{
	return false;
}

bool AAstroGameState::HasSaveGameCacheBeenEnumerated()
{
	return false;
}

void AAstroGameState::AddAndPrioritizeNewPlayerSpawnLocation(AActor* spawn)
{

}

void AAstroGameState::RemoveNewPlayerSpawnLocation(AActor* spawn)
{

}

void AAstroGameState::DestroyAllSpawnedStartingItems()
{

}

void AAstroGameState::RegisterSpawnedStartingItem(APhysicalItem* item)
{

}

void AAstroGameState::UnregisterSpawnedStartingItem(APhysicalItem* item)
{

}

TArray<APhysicalItem*> AAstroGameState::GetStartingItemArrayRef()
{
	TArray<APhysicalItem*> x;
	return x;
}

/*bool AAstroGameState::IsProbeUnlocked(AAstroCharacter* character, FName ProbeName)
{
	return false;
}*/

/*void AAstroGameState::AuthoritySetWandererRealityTearOpenState(EWandererRealityTearOpenState state)
{

}

EWandererRealityTearOpenState AAstroGameState::AuthorityGetWandererRealityTearOpenState()
{
	return 0;
}

FScannableStatus AAstroGameState::GetNearestRelevantScannable(AAstroCharacter* player)
{

}*/

void AAstroGameState::OnAuthorityResearchPointBalanceChanged(float NewPointBalance)
{

}

void AAstroGameState::OnAuthorityKnownItemsChanged(TArray<TSubclassOf<UItemType>> newKnownItems)
{

}

void AAstroGameState::OnAuthorityUnlockedItemsChanged(TArray<TSubclassOf<UItemType>> NewUnlockedItems)
{

}

void AAstroGameState::BroadcastResearchPointBalanceChanged()
{

}

void AAstroGameState::BroadcastKnownItemsChanged()
{

}

void AAstroGameState::BroadcastUnlockedItemsChanged()
{

}

void AAstroGameState::BroadcastOnCreativeModeCatalogUnlockedChanged()
{

}

bool AAstroGameState::IsCreativeModeActive()
{
	return false;
}

void AAstroGameState::SetCreativeModeActive(bool creativeModeActive)
{

}

bool AAstroGameState::IsFuelFreeCreative()
{
	return false;
}

void AAstroGameState::SetFuelFreeCreative(bool freeFuelEnabled)
{

}

bool AAstroGameState::IsCatalogUnlockedCreative()
{
	return false;
}

void AAstroGameState::SetCatalogUnlockedCreative(bool catalogUnlocked)
{

}

bool AAstroGameState::IsOxygenFreeCreative()
{
	return false;
}

void AAstroGameState::SetOxygenFreeCreative(bool oxygenFree)
{

}

bool AAstroGameState::IsInvincibleCreative()
{
	return false;
}

void AAstroGameState::SetInvincibleCreative(bool invincible)
{

}

bool AAstroGameState::IsInvisibleToHazardsCreative()
{
	return false;
}

void AAstroGameState::SetInvisibleToHazardsCreative(bool invisibleToHazards)
{

}

bool AAstroGameState::IsBackpackPowerUnlimitedCreative()
{
	return false;
}

void AAstroGameState::SetBackpackPowerUnlimitedCreative(bool backpackPowerUnlimited)
{

}

bool AAstroGameState::IsAchievementProgressionDisabled()
{
	return false;
}

bool AAstroGameState::HasEverBeenCreativeGame()
{
	return false;
}

bool AAstroGameState::HasEverBeenIndividualDedicatedServerGame()
{
	return false;
}

/*EAchievementProgressionState AAstroGameState::GetAchievementProgressionState()
{

}*/

void AAstroGameState::SetAchievementProgressionDisabledCreative(bool achievementProgressionDisabled)
{

}

void AAstroGameState::SetNewGameDropshipSequenceActive(bool isActive)
{

}

bool AAstroGameState::GetIsNewGameDropshipSequenceActive()
{
	return false;
}

/*void AAstroGameState::SaveGameSerializeCustom(UAstroSaveCustomArchiveProxy* proxy)
{

}*/

void AAstroGameState::NotifyOutroCinematicCompleted()
{

}

void AAstroGameState::OnRep_CreativeModeSettings()
{

}

void AAstroGameState::OnRep_IsOutroCinematicActive()
{

}

void AAstroGameState::BroadcastUnlockedVintageProbesChanged()
{

}