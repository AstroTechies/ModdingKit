#include "CrackableActorComponent.h"
#include "Net/UnrealNetwork.h"

class UCrackableActorComponent;

void UCrackableActorComponent::UpdateScreenScaleRatioAndCameraSpaceOffset(float ratio, FVector Offset) {
}

void UCrackableActorComponent::SetCracked(bool cracked) {
}

void UCrackableActorComponent::SetClosedRelativeTransform(const FTransform& ClosedRelativeTransform) {
}

void UCrackableActorComponent::OnRep_StartingRelativeTransform() {
}

void UCrackableActorComponent::OnRep_Cracked() {
}

void UCrackableActorComponent::OnParentCrackedChanged(UCrackableActorComponent* parentCrackableActorComponent, bool bParentCracked) {
}

void UCrackableActorComponent::OnClickUnhandled() {
}

bool UCrackableActorComponent::IsExaminable() const {
    return false;
}

bool UCrackableActorComponent::GetFullyOpen() const {
    return false;
}

bool UCrackableActorComponent::GetFullyClosed() const {
    return false;
}

bool UCrackableActorComponent::GetCracked() const {
    return false;
}

FTransform UCrackableActorComponent::GetClosedRelativeTransform() const {
    return FTransform{};
}

bool UCrackableActorComponent::CracksOnlyOnExamine() const {
    return false;
}

bool UCrackableActorComponent::CanClickToClose() const {
    return false;
}

void UCrackableActorComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UCrackableActorComponent, ReplicationData);
    DOREPLIFETIME(UCrackableActorComponent, StartingRelativeTransform);
}

UCrackableActorComponent::UCrackableActorComponent() {
    this->CrackingSpeed = 10.00f;
    this->Method = ECrackableActorMethod::Hover;
    this->NetworkingPolicy = ECrackableActorNetworkingPolicy::LocalOnlyNoNetworking;
    this->bEncapsulateClicksWhenClosed = true;
    this->bDisableComponentClicksWhenClosed = true;
    this->bCracked = false;
    this->bClickToClose = true;
    this->bCloseOnUnhandledClick = true;
    this->bCloseWhenParentCrackableStateChanges = true;
    this->bExaminable = false;
    this->bCracksOnlyOnExamine = false;
    this->ClientScaleWhenCracked = 1.00f;
    this->ScreenScaleRatio = 0.00f;
    this->HoverHeight = 250.00f;
    this->HideThreshold = 0.03f;
    this->PivotAngle = 3.14f;
}

