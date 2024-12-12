#include "AstroGameMenuPopoutWidgetContentsBase.h"

UAstroGameMenuPopoutWidgetContentsBase::UAstroGameMenuPopoutWidgetContentsBase() {
    this->OwningFocusItem = NULL;
    this->InitialFocusCoordinates = 0;
    this->ParentPopoutWidget = NULL;
}


void UAstroGameMenuPopoutWidgetContentsBase::HandleNavigationBackRequest_Implementation() {
}


