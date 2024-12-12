#include "LocalizedTerrainReversionComponent.h"

ULocalizedTerrainReversionComponent::ULocalizedTerrainReversionComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Radius = 400.00f;
    this->SoftEdgeStartRadius = 0.00f;
    this->ExtendedMaterialOverrideRadius = 0.00f;
    this->Intensity = 1.00f;
    this->UseOverrideMaterial = false;
    this->Enabled = true;
    this->m_planet = NULL;
}

void ULocalizedTerrainReversionComponent::OwnerDestroyed(AActor* DestroyedActor) {
}


