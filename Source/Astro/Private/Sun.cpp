#include "Sun.h"
#include "Components/DirectionalLightComponent.h"

class UMaterialInstanceDynamic;

void ASun::SetSunMaterialInstance(UMaterialInstanceDynamic* Instance) {
}

ASun::ASun() {
    this->SunRadius = 119924.91f;
    this->RevealMaxRadius = 510000.00f;
    this->PlanetSelectBorderThickness = 0.10f;
    this->PlanetSelectRevealSpeed = 4.00f;
    this->SunLight = CreateDefaultSubobject<UDirectionalLightComponent>(TEXT("Sun Light"));
}

