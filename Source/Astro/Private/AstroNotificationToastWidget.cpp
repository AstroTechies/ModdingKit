#include "AstroNotificationToastWidget.h"

UAstroNotificationToastWidget::UAstroNotificationToastWidget() {
    this->bWidgetShouldRemainPresented = false;
    this->MaxLifetime = 5.00f;
}



void UAstroNotificationToastWidget::MarkNotificationForDestruction() {
}


