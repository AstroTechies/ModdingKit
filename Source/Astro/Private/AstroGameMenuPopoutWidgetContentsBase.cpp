#include "AstroGameMenuPopoutWidgetContentsBase.h"


void UAstroGameMenuPopoutWidgetContentsBase::HandleNavigationBackRequest_Implementation() {
}

UAstroGameMenuPopoutWidgetContentsBase::UAstroGameMenuPopoutWidgetContentsBase() {
    this->OwningFocusItem = NULL;
    this->InitialFocusCoordinates = 0;
    this->ParentPopoutWidget = NULL;
}

