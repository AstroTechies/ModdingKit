#include "ButtonComponent.h"

class UPrimitiveComponent;
class UMaterialInterface;
class UMaterialInstanceDynamic;

void UButtonComponent::SetShellComponent(UPrimitiveComponent* NewShellComponent) {
}

void UButtonComponent::SetFlashing(bool Flashing) {
}

void UButtonComponent::SetCollisionComponent(UPrimitiveComponent* NewCollisionComponent) {
}

void UButtonComponent::SetAllShellMaterials(UMaterialInterface* Material) {
}

void UButtonComponent::OnShellReleased(UPrimitiveComponent* Component, FKey ButtonPressed) {
}

void UButtonComponent::OnShellClick(UPrimitiveComponent* Component, FKey ButtonPressed) {
}

void UButtonComponent::OnEndHover(UPrimitiveComponent* Component) {
}

void UButtonComponent::OnClick(UPrimitiveComponent* Component, FKey ButtonPressed) {
}

void UButtonComponent::OnBeginHover(UPrimitiveComponent* Component) {
}

bool UButtonComponent::IsEnabled() {
    return false;
}

void UButtonComponent::Enable(bool Enabled) {
}

UMaterialInstanceDynamic* UButtonComponent::CreateShellDynamicMaterialInstance(int32 MaterialIndex, UMaterialInterface* Material) {
    return NULL;
}

UButtonComponent::UButtonComponent() {
    this->IconMesh = NULL;
    this->IconMesh_Static = NULL;
    this->IconAnimation = NULL;
    this->SpinIcon = true;
    this->UseToolTip = false;
    this->DoServerClick = true;
    this->ClientEnableAllowed = false;
    this->Shape = ButtonShape::Rectangle;
    this->shellComponent = NULL;
    this->collisionComponent = NULL;
    this->Icon = NULL;
    this->ToolTipScene = NULL;
    this->TextRenderer = NULL;
    this->ShellMaterial = NULL;
}

