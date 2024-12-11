#include "VintageProbeUnlockBehaviorDefinition.h"
#include "VintageProbeUnlockBehavior.h"

UVintageProbeUnlockBehaviorDefinition::UVintageProbeUnlockBehaviorDefinition() {
    this->Name = TEXT("Default__VintageProbeUnlockBehaviorDefinition");
    this->RuntimeSubobjectType = UVintageProbeUnlockBehavior::StaticClass();
    this->RealityTearObject = NULL;
    this->RealityTearFlickerObject = NULL;
}


