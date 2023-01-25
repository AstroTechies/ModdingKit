#include "DeformTool.h"
#include "DeformEventReceiver.h"
#include "DeformToolCameraContext.h"
#include "Net/UnrealNetwork.h"
#include "Templates/SubclassOf.h"

class AAstroPlanet;
class APhysicalItem;
class APlayController;
class UAugmentComponent;
class UClickQuery;
class UDeformTargetComponent;
class UItemType;
class UMaterialInterface;

bool ADeformTool::UpdateTerrainSample(AAstroPlanet* Planet, const FVector& Location) {
    return false;
}

void ADeformTool::UpdateAugmentModifiedProperties() {
}

void ADeformTool::TryEquipAugment(UAugmentComponent* augment, EAugmentProperty augmentProperty) {
}

void ADeformTool::ToolClickQuery(UClickQuery* ClickQuery) {
}

TSubclassOf<UItemType> ADeformTool::TakeTerrainResource_Implementation() {
    return NULL;
}

void ADeformTool::SetSuspendBrushPositionUpdate(bool doSuspend) {
}

void ADeformTool::SetCreativeToolRange(float NewVal) {
}

void ADeformTool::SetCreativeBaseDeformationScale(float NewVal) {
}

void ADeformTool::SetCreativeBaseDeformationIntensity(float NewVal) {
}

void ADeformTool::ServerSetIsIgnoringTerrainHardnessCreative_Implementation(bool IgnoreTerrainHardness) {
}
bool ADeformTool::ServerSetIsIgnoringTerrainHardnessCreative_Validate(bool IgnoreTerrainHardness) {
    return true;
}

void ADeformTool::ServerSendSampledTerrainUpdate_Implementation(const FVector& Location) {
}
bool ADeformTool::ServerSendSampledTerrainUpdate_Validate(const FVector& Location) {
    return true;
}

void ADeformTool::ServerSendBrushUpdates_Implementation(const FReplicatedBrushState& repState) {
}
bool ADeformTool::ServerSendBrushUpdates_Validate(const FReplicatedBrushState& repState) {
    return true;
}

void ADeformTool::ServerRequestNewMaterialWithTerrainProperties_Implementation(AAstroPlanet* Planet, const FVoxelMaterialProperties& TerrainProperties, UMaterialInterface* CustomMaterial, int32 creativeModePaintMaterialIndex) {
}
bool ADeformTool::ServerRequestNewMaterialWithTerrainProperties_Validate(AAstroPlanet* Planet, const FVoxelMaterialProperties& TerrainProperties, UMaterialInterface* CustomMaterial, int32 creativeModePaintMaterialIndex) {
    return true;
}

void ADeformTool::ServerEndDeforming_Implementation() {
}
bool ADeformTool::ServerEndDeforming_Validate() {
    return true;
}

void ADeformTool::ServerDoDeformTarget_Implementation(UDeformTargetComponent* deformTarget) {
}
bool ADeformTool::ServerDoDeformTarget_Validate(UDeformTargetComponent* deformTarget) {
    return true;
}

void ADeformTool::ServerCreativeModeColorPick_Implementation(const FVector& Location) {
}
bool ADeformTool::ServerCreativeModeColorPick_Validate(const FVector& Location) {
    return true;
}

void ADeformTool::ServerCreativeModeColorChange_Implementation(const FVoxelMaterialProperties& Properties, const FVector& Location, UMaterialInterface* CustomMaterial, int32 creativeModePaintMaterialIndex) {
}
bool ADeformTool::ServerCreativeModeColorChange_Validate(const FVoxelMaterialProperties& Properties, const FVector& Location, UMaterialInterface* CustomMaterial, int32 creativeModePaintMaterialIndex) {
    return true;
}

void ADeformTool::ServerBeginDeforming_Implementation() {
}
bool ADeformTool::ServerBeginDeforming_Validate() {
    return true;
}

void ADeformTool::PhysicalItemUnslotted(APhysicalItem* ItemOwner) {
}

void ADeformTool::PhysicalItemSlotted(APhysicalItem* ItemOwner) {
}

void ADeformTool::OnUseLegacyAddModeChanged(bool UseLegacyAddMode) {
}

void ADeformTool::OnReplicated_TerrainSample() {
}

void ADeformTool::OnReplicated_ColorPickState() {
}



void ADeformTool::OnCreativeModeActiveStateChanged(bool IsEnabled) {
}



bool ADeformTool::IsToolDeployed() {
    return false;
}


void ADeformTool::IncrementCreativeBaseDeformationIntensity(float Delta) {
}

void ADeformTool::IncrementCreativeBaseBrushDeformationScale(float Delta) {
}

bool ADeformTool::HasTankReservesNecessaryToAdditivelyDeform() {
    return false;
}

bool ADeformTool::HasSpaceLeftInTanks() {
    return false;
}

void ADeformTool::HandleTerrainTool(APlayController* Controller, const FHitResult& toolHit, const FClickResult& ClickResult, bool startedInteraction, bool isUsingTool, bool justActivated, bool canUse) {
}

float ADeformTool::GetSedimentFlowRate() {
    return 0.0f;
}

float ADeformTool::GetSedimentDeformationDelta() {
    return 0.0f;
}

float ADeformTool::GetSedimentAvailable() {
    return 0.0f;
}

bool ADeformTool::GetPowerLevelInhibitedFromAugment() {
    return false;
}

bool ADeformTool::GetOwnerBackpackRasied() {
    return false;
}

FVoxelMaterial ADeformTool::GetMaterialFromAugment() {
    return FVoxelMaterial{};
}

bool ADeformTool::GetIsIgnoringTerrainHardnessCreative() {
    return false;
}

bool ADeformTool::GetIsDeforming_Implementation() {
    return false;
}


bool ADeformTool::GetFixedAlignmentFromAugment() {
    return false;
}

float ADeformTool::GetEffectiveIndicatorScale() {
    return 0.0f;
}

float ADeformTool::GetEffectiveDeformationIntensity() {
    return 0.0f;
}

float ADeformTool::GetEffectiveBrushScale() {
    return 0.0f;
}

float ADeformTool::GetDeformTier() const {
    return 0.0f;
}

FVector ADeformTool::GetDeformLocation_Implementation() {
    return FVector{};
}

bool ADeformTool::GetDeformationIsActive() {
    return false;
}

float ADeformTool::GetDeformationIntensityModifierFromAugment() {
    return 0.0f;
}

float ADeformTool::GetCreativeToolRange() {
    return 0.0f;
}

float ADeformTool::GetCreativeDeformationIntensityNormalized() {
    return 0.0f;
}

float ADeformTool::GetCreativeBaseDeformationIntensity() {
    return 0.0f;
}

float ADeformTool::GetCreativeBaseBrushDeformationScale() {
    return 0.0f;
}

float ADeformTool::GetBrushSizeModifierFromAugment() {
    return 0.0f;
}

float ADeformTool::GetAugmentedTerrainHardness() {
    return 0.0f;
}

void ADeformTool::DetermineSedimentTankAmount() {
}

void ADeformTool::Deactivated() {
}

void ADeformTool::CycleModeRight() {
}

void ADeformTool::CycleModeLeft() {
}

void ADeformTool::CheckForOrphanedTool() {
}

void ADeformTool::CheckAugmentsHavePower() {
}

void ADeformTool::ChangeInAttachedAugments() {
}

float ADeformTool::AuthorityGetEffectiveHardnessTier() {
    return 0.0f;
}

void ADeformTool::AdjustSedimentTankAmountFromDeformationDelta(float deformationDelta) {
}

void ADeformTool::Activated() {
}

void ADeformTool::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ADeformTool, bSedimentTankReservesState);
    DOREPLIFETIME(ADeformTool, RepBrushState);
    DOREPLIFETIME(ADeformTool, RepAugmentState);
    DOREPLIFETIME(ADeformTool, RepCreativeColorPickState);
    DOREPLIFETIME(ADeformTool, RepTerrainSample);
    DOREPLIFETIME(ADeformTool, TotalSedimentAvailable);
    DOREPLIFETIME(ADeformTool, TotalSedimentCapacity);
    DOREPLIFETIME(ADeformTool, SedimentDeformationDelta);
    DOREPLIFETIME(ADeformTool, bDeformationActive);
    DOREPLIFETIME(ADeformTool, bDeformationFullPower);
    DOREPLIFETIME(ADeformTool, bCreativeModeIgnoreHardness);
}

ADeformTool::ADeformTool() {
    this->AudioSurfaceTypeSwitchState.AddDefaulted(9);
    this->DeformFXActor = NULL;
    this->TerrainBrushActor = NULL;
    this->bSedimentTankReservesState = EDeformToolSedimentTankReservesState::NoReserves;
    this->usingTool = NULL;
    this->OwningController = NULL;
    this->OwningCharacter = NULL;
    this->TerrainBrush = NULL;
    this->FXSpawnComponent = NULL;
    this->EventReceiver = CreateDefaultSubobject<UDeformEventReceiver>(TEXT("EventReceiver"));
    this->PowerComponent = NULL;
    this->BaseBrushDeformationScale = 600.00f;
    this->BaseBrushIndicatorScale = 1.00f;
    this->BaseDeformationItensity = 1.00f;
    this->BaseCreativeDeformationIntensity = 1.00f;
    this->CreativeBaseDeformationIntensityMin = 1.00f;
    this->CreativeBaseDeformationIntensityMax = 1.00f;
    this->CreativeBaseBrushDeformationScaleMin = 1.00f;
    this->CreativeBaseBrushDeformationScaleMax = 1.00f;
    this->CreativeToolRangeMax = 1.00f;
    this->CreativeBaseBrushDeformationIntensityAdjustmentIncrement = 1.00f;
    this->CreativeBaseBrushDeformationScaleAdjustmentIncrement = 1.00f;
    this->SphereCastRatio = 0.25f;
    this->LerpRate = 0.25f;
    this->PlayerSafeZone = 200.00f;
    this->ToolRange = 1500.00f;
    this->LowPowerMultiplier = 0.30f;
    this->SedimentBaseRate = 0.33f;
    this->SedimentDeformationRatio = 0.00f;
    this->SedimentFullySuppliedAmount = 0.20f;
    this->FXFrequency = 8.00f;
    this->FXSubtractVelocity = 100.00f;
    this->FXAddVelocity = 100.00f;
    this->FXRadialVelocity = 10.00f;
    this->FXSubtractVelocityRandomness = 0.50f;
    this->FXScale = 0.20f;
    this->FXScaleRandomness = 0.20f;
    this->FXSubtractSpawnHeight = 100.00f;
    this->FXAddSpawnHeight = 500.00f;
    this->MiningValue = 0.00f;
    this->DeformEffectComponent = NULL;
    this->BurnoffEffectComponent = NULL;
    this->CameraContext = CreateDefaultSubobject<UDeformToolCameraContext>(TEXT("DeformToolCameraContext"));
    this->BrushMaterialIndex = 4294967295;
    this->TotalSedimentAvailable = 0.00f;
    this->TotalSedimentCapacity = 0.00f;
    this->SedimentDeformationDelta = 0.00f;
    this->DeformTier = 0.00f;
    this->Operation = EDeformType::Subtract;
    this->bDeformationActive = false;
    this->bDeformationFullPower = true;
    this->bCreativeModeIgnoreHardness = false;
    this->IsOwnedTool = true;
    this->ToolActive = false;
    this->TerrainStreamEffectsActive = false;
    this->AudioBurnOffPlaying = false;
    this->MinedMineral = false;
}

