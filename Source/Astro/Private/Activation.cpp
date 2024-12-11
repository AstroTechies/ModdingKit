#include "Activation.h"

UActivation::UActivation() {
    this->m_bActive = false;
}

bool UActivation::Update(bool Active) {
    return false;
}

void UActivation::UnbindTo(UActivation* Other) {
}

void UActivation::Toggle() {
}

bool UActivation::IsActive() {
    return false;
}

void UActivation::Deactivate() {
}

void UActivation::BindTo(UActivation* Other) {
}

void UActivation::Activate() {
}


