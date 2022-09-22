#include "VehicleDrill.h"
#include "Net/UnrealNetwork.h"
#include "ControlComponent.h"
#include "DeformEventReceiver.h"
#include "PowerComponent.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SceneComponent -FallbackName=SceneComponent

class UMaterialInterface;
class AAstroPlanet;
class AVehicleDrill;
class AAstroPlayerController;
class UStorageChassisComponent;
class APhysicalItem;

void AVehicleDrill::UpdateTerrainDeformationParticles(bool SystemEnabled, int32 HardnessDelta) {
}





void AVehicleDrill::ToggleDrillUsageForTunnelBoring() {
}

void AVehicleDrill::ServerUpdateToolState_Implementation(bool ToolIsActive, EVehicleDrillToolMode DrillMode) {
}
bool AVehicleDrill::ServerUpdateToolState_Validate(bool ToolIsActive, EVehicleDrillToolMode DrillMode) {
    return true;
}

void AVehicleDrill::ServerRequestNewMaterialWithTerrainProperties_Implementation(AAstroPlanet* Planet, const FVoxelMaterialProperties& TerrainProperties, UMaterialInterface* CustomMaterial, int32 creativeModePaintMaterialIndex) {
}
bool AVehicleDrill::ServerRequestNewMaterialWithTerrainProperties_Validate(AAstroPlanet* Planet, const FVoxelMaterialProperties& TerrainProperties, UMaterialInterface* CustomMaterial, int32 creativeModePaintMaterialIndex) {
    return true;
}

void AVehicleDrill::ResetExcessTerrainCollectionFlag() {
}



void AVehicleDrill::OnRep_VehicleDrillSedimentReplicationData() {
}

void AVehicleDrill::OnRep_VehicleDrillReplicationData() {
}

void AVehicleDrill::MulticastPlayDrillStartWithInsufficientSoilEffect_Implementation() {
}

void AVehicleDrill::MulticastPlayDrillStartWithInsufficientPowerEffect_Implementation() {
}

bool AVehicleDrill::IsToolActive() const {
    return false;
}

void AVehicleDrill::HandleVehicleUnmanned(AAstroPlayerController* VehicleDriver) {
}

void AVehicleDrill::HandleVehicleManned(AAstroPlayerController* VehicleDriver) {
}

void AVehicleDrill::HandleTunnelBoringDrillBecameActiveOnMyRover(AVehicleDrill* DrillThatBecameActive) {
}

void AVehicleDrill::HandleTerraianDeformationDensityDeltaReceived(float DensityDelta) {
}

void AVehicleDrill::HandleRemovedFromSlot(bool NewOwner) {
}

void AVehicleDrill::HandlePlacedInSlot() {
}

void AVehicleDrill::HandleDummyDrillRemovedFromSlot(AVehicleDrill* DummyDrillRemoved) {
}

void AVehicleDrill::HandleDestroyedWhileInSlot(APhysicalItem* DestroyedActor) {
}

void AVehicleDrill::HandleDeactivatedAsExcavator() {
}

void AVehicleDrill::HandleActivatedAsExcavator() {
}


UStorageChassisComponent* AVehicleDrill::GetOutermostStorage() {
    return NULL;
}

bool AVehicleDrill::DidCollectExcessTerrain() const {
    return false;
}

void AVehicleDrill::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AVehicleDrill, VehicleDrillReplicatedState);
    DOREPLIFETIME(AVehicleDrill, DummyLinkedDrills);
    DOREPLIFETIME(AVehicleDrill, VehicleDrillReplicatedSedimentState);
}

AVehicleDrill::AVehicleDrill() {
    this->SedimentDeformationRatio = 0.00f;
    this->NeutralDotProdBetweenCameraAndRoverUp = 0.00f;
    this->DeformationTier = 0.00f;
    this->FoliageDestructionMassThreshold = 1000.00f;
    this->DestructionRadiusScaleFromDeformSize = 1.00f;
    this->ExcessTerrainCollectedThresholdForBurnoffEffect = 0;
    this->CameraPitchToDrillPitchMapping = NULL;
    this->SteeringAngleToDrillRollMapping = NULL;
    this->MaximumRollAdjustment = 0.00f;
    this->SteeringAngleToDrillYawMapping = NULL;
    this->BirdsEyeDotVal = 0.00f;
    this->WormsEyeDotVal = 0.00f;
    this->MaxSlope = 45.00f;
    this->MaxDrillSlope = 40.00f;
    this->ControlComponent = CreateDefaultSubobject<UControlComponent>(TEXT("Control"));
    this->DeformEventReceiver = CreateDefaultSubobject<UDeformEventReceiver>(TEXT("DeformEventReceiver"));
    this->PowerComponent = CreateDefaultSubobject<UPowerComponent>(TEXT("PowerComponent"));
    this->DeformVisualizer = NULL;
    this->FoliageDestructionVisualizer = NULL;
    this->ExcavationDeformationOriginMarker = CreateDefaultSubobject<USceneComponent>(TEXT("ExcavationDeformationOriginMarker"));
    this->TunnelBoringUI_Wrapper = NULL;
    this->PivotingUI_Wrapper = NULL;
    this->TerrainDeformationParticles = NULL;
    this->TiltIndicatorWrapper = NULL;
    this->TiltUpIndicatorWrapper = NULL;
    this->TiltDownIndicatorWrapper = NULL;
    this->SlopeGaugeExtent = 0.00f;
    this->TunnelBoringRover = NULL;
    this->CraneSubclass = NULL;
    this->ConsumedSedimentDebt = 0;
}

