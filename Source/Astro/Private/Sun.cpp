#include "Sun.h"
#include "Components/DirectionalLightComponent.h"

ASun::ASun() {
    this->SunLight = CreateDefaultSubobject<UDirectionalLightComponent>(TEXT("Sun Light"));
}

