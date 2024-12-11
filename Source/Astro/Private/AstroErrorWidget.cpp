#include "AstroErrorWidget.h"

UAstroErrorWidget::UAstroErrorWidget() : UUserWidget(FObjectInitializer::Get()) {
    this->Timer = 0.00f;
    this->DefaultTimeToDisplay = 10.00f;
}


