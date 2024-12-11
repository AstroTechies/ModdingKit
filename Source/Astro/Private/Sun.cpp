#include "Sun.h"
#include "Components/DirectionalLightComponent.h"
#include "Components/SceneComponent.h"

ASun::ASun(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    this->SunRadius = 119924.91f;
    this->RevealMaxRadius = 510000.00f;
    this->PlanetSelectBorderThickness = 0.10f;
    this->PlanetSelectRevealSpeed = 4.00f;
    this->SunLight = CreateDefaultSubobject<UDirectionalLightComponent>(TEXT("Sun Light"));
    this->SunLight->SetupAttachment(RootComponent);
}

void ASun::SetSunMaterialInstance(UMaterialInstanceDynamic* Instance) {
}


