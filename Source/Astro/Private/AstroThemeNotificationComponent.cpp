#include "AstroThemeNotificationComponent.h"

UAstroThemeNotificationComponent::UAstroThemeNotificationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->OnlyDestroyBurried = false;
}

void UAstroThemeNotificationComponent::ValidateThemesStatus() {
}

void UAstroThemeNotificationComponent::OnThemeStatusChanged() {
}

void UAstroThemeNotificationComponent::CloneToActor(AActor* Actor) {
}


