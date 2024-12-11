#include "AstroEntityComponentSubobjectDefinition.h"

UAstroEntityComponentSubobjectDefinition::UAstroEntityComponentSubobjectDefinition() {
    this->Name = TEXT("Default__AstroEntityComponentSubobjectDefinition");
    this->RuntimeSubobjectType = NULL;
    this->TickGroup = EAstroEntityComponentSubobjectTickGroup::PrePhysics;
}


