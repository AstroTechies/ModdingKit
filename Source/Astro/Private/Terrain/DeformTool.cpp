// Fill out your copyright notice in the Description page of Project Settings.


#include "DeformTool.h"

float ADeformTool::GetDeformTier()
{
	return 0;
}

FVector ADeformTool::GetDeformLocation()
{
	return FVector();
}

bool ADeformTool::GetIsDeforming()
{
	return false;
}

bool ADeformTool::GetOwnerBackpackRasied()
{
	return false;
}

float ADeformTool::GetAugmentedTerrainHardness()
{
	return 0;
}

float ADeformTool::GetEffectiveBrushScale()
{
	return 0;
}

float ADeformTool::GetEffectiveIndicatorScale()
{
	return 0;
}

float ADeformTool::GetEffectiveDeformationIntensity()
{
	return 0;
}

float ADeformTool::AuthorityGetEffectiveHardnessTier()
{
	return 0;
}

void ADeformTool::AdjustSedimentTankAmountFromDeformationDelta(float deformationDelta)
{

}

float ADeformTool::GetSedimentFlowRate()
{
	return 0;
}

float ADeformTool::GetSedimentDeformationDelta()
{
	return 0;
}

float ADeformTool::GetSedimentAvailable()
{
	return 0;
}

bool ADeformTool::GetDeformationIsActive()
{
	return false;
}

void ADeformTool::CheckForOrphanedTool()
{

}

bool ADeformTool::IsToolDeployed()
{
	return false;
}

void ADeformTool::IncrementCreativeBaseDeformationIntensity(float delta)
{

}

void ADeformTool::IncrementCreativeBaseBrushDeformationScale(float delta)
{

}

void ADeformTool::SetCreativeBaseDeformationIntensity(float newVal)
{

}

void ADeformTool::SetCreativeToolRange(float newVal)
{

}

void ADeformTool::SetCreativeBaseDeformationScale(float newVal)
{

}

float ADeformTool::GetCreativeToolRange()
{
	return 0;
}

float ADeformTool::GetCreativeBaseDeformationIntensity()
{
	return 0;
}

float ADeformTool::GetCreativeDeformationIntensityNormalized()
{
	return 0;
}

float ADeformTool::GetCreativeBaseBrushDeformationScale()
{
	return 0;
}

void ADeformTool::OnReplicated_TerrainSample()
{

}

void ADeformTool::OnReplicated_ColorPickState()
{

}

void ADeformTool::Activated()
{

}

void ADeformTool::Deactivated()
{

}

void ADeformTool::CycleModeRight()
{

}

void ADeformTool::CycleModeLeft()
{

}

void ADeformTool::OnUseLegacyAddModeChanged(bool useLegacyAddMode)
{

}

void ADeformTool::OnCreativeModeActiveStateChanged(bool isEnabled)
{

}

bool ADeformTool::HasTankReservesNecessaryToAdditivelyDeform()
{
	return false;
}

bool ADeformTool::HasSpaceLeftInTanks()
{
	return false;
}

float ADeformTool::GetBrushSizeModifierFromAugment()
{
	return 0;
}

float ADeformTool::GetDeformationIntensityModifierFromAugment()
{
	return 0;
}

bool ADeformTool::GetPowerLevelInhibitedFromAugment()
{
	return false;
}

bool ADeformTool::GetFixedAlignmentFromAugment()
{
	return false;
}

bool ADeformTool::UpdateTerrainSample(AAstroPlanet* Planet, FVector Location)
{
	return false;
}

void ADeformTool::ToolClickQuery(UClickQuery* clickQuery)
{

}

void ADeformTool::PhysicalItemSlotted(APhysicalItem* ItemOwner)
{

}

void ADeformTool::PhysicalItemUnslotted(APhysicalItem* ItemOwner)
{

}

void ADeformTool::ChangeInAttachedAugments()
{

}

void ADeformTool::CheckAugmentsHavePower()
{

}

void ADeformTool::UpdateAugmentModifiedProperties()
{

}

void ADeformTool::DetermineSedimentTankAmount()
{

}

bool ADeformTool::GetIsIgnoringTerrainHardnessCreative()
{
	return false;
}