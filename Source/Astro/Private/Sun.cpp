#include "Sun.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=DirectionalLightComponent -FallbackName=DirectionalLightComponent

ASun::ASun() {
    this->SunLight = CreateDefaultSubobject<UDirectionalLightComponent>(TEXT("Sun Light"));
}

