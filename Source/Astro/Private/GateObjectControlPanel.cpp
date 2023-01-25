#include "GateObjectControlPanel.h"
#include "Components/SceneComponent.h"
#include "Net/UnrealNetwork.h"
#include "TooltipComponent.h"

class UPrimitiveComponent;
class USolarSystem;

void AGateObjectControlPanel::SetContext(EGateObjectControlPanelContext newContext) {
}

void AGateObjectControlPanel::SelectControlNode(int32 controlNodeIndex) {
}

void AGateObjectControlPanel::OnSolarSystemInitialized(USolarSystem* SolarSystem) {
}



void AGateObjectControlPanel::OnRep_CurrentLocationControlNodeIndex() {
}

void AGateObjectControlPanel::OnGateStationSpawned() {
}

void AGateObjectControlPanel::OnGateObjectActivated(const FGateObjectReference& ActivatedGateObjectRef) {
}

void AGateObjectControlPanel::OnControlNodeEndCursorOver(UPrimitiveComponent* hoveredControlNodeMesh) {
}

void AGateObjectControlPanel::OnControlNodeClicked(UPrimitiveComponent* clickedControlNodeMesh, FKey ButtonPressed) {
}


void AGateObjectControlPanel::OnControlNodeBeginCursorOver(UPrimitiveComponent* hoveredControlNodeMesh) {
}

bool AGateObjectControlPanel::IsControlNodeGateObjectActivated(int32 controlNodeIndex) const {
    return false;
}




void AGateObjectControlPanel::CenterControlNodeInView(int32 controlNodeIndex, float InterpolationTime) {
}

void AGateObjectControlPanel::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AGateObjectControlPanel, CurrentLocationControlNodeIndex);
}

AGateObjectControlPanel::AGateObjectControlPanel() {
    this->DefaultInertIndicatorMaterial = NULL;
    this->DefaultActiveIndicatorMaterial = NULL;
    this->CenteredNodeRotationOffset = 45.00f;
    this->ChamberIndicatorOffsetDistance = 500.00f;
    this->SolarSystemViewRadius = 500.00f;
    this->ScaleInterpolationDuration = 1.00f;
    this->CurrentContext = EGateObjectControlPanelContext::Planet;
    this->SelectedControlNodeIndex = -1;
    this->CurrentLocationControlNodeIndex = -1;
    this->CrackedRoot = CreateDefaultSubobject<USceneComponent>(TEXT("CrackedRoot"));
    this->ControlNodeRoot = CreateDefaultSubobject<USceneComponent>(TEXT("ControlNodeRoot"));
    this->TooltipComponent = CreateDefaultSubobject<UTooltipComponent>(TEXT("TooltipComponent"));
    this->SunIndicatorComponent = NULL;
}

