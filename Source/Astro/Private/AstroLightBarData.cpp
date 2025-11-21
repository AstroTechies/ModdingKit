#include "AstroLightBarData.h"

FAstroLightBarData::FAstroLightBarData() {
    this->LightBarPriority = 0;
    this->LightBarColorCurve = NULL;
    this->LightBarColor = EAstroColor::None;
    this->MaxTime = 0.00f;
    this->bIsLooping = false;
    this->MinOpacity = 0.00f;
    this->bIsPulsating = false;
    this->bUseLightBarColorByDefault = false;
}

