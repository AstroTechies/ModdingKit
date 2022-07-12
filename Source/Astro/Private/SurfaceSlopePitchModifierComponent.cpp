#include "SurfaceSlopePitchModifierComponent.h"

USurfaceSlopePitchModifierComponent::USurfaceSlopePitchModifierComponent() {
    this->UpperLimit = 20.00f;
    this->LowerLimit = -45.00f;
    this->bPerformGroundCheck = true;
    this->GroundCheckTraceDistance = 250.00f;
}

