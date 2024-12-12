#include "Crackable.h"

UCrackable::UCrackable(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Method = ECrackableMethod::Hover;
    this->UseSimulatingForOrigin = false;
    this->CrackingSpeed = 10.00f;
    this->ScreenScaleRatio = 0.00f;
    this->ClickToCrack = false;
    this->HoverHeight = 250.00f;
    this->HideWhenFullyCracked = false;
    this->AddCameraTargetOffset = true;
    this->HideThreshold = 0.03f;
    this->PivotAngle = 3.14f;
    this->cracked = false;
    this->TargetCrackedValue = 0.00f;
    this->CrackedValue = 0.00f;
    this->CameraCollisionOffset = 0.00f;
    this->CameraCollisionSize = 100.00f;
    this->bShowCollisionDebug = false;
    this->Origin = NULL;
}

void UCrackable::ToggleCracked() {
}

void UCrackable::SetCracked(bool NewCracked) {
}

void UCrackable::OnMoved(bool FromTool) {
}

void UCrackable::OnComponentClicked(UPrimitiveComponent* Component, FKey Key) {
}

void UCrackable::OnClickUnhandled() {
}

void UCrackable::AddChildActor(UChildActorComponent* ChildActor) {
}

void UCrackable::AddChild(UCrackable* Child) {
}


