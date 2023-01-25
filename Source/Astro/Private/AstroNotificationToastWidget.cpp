#include "AstroNotificationToastWidget.h"



void UAstroNotificationToastWidget::MarkNotificationForDestruction() {
}

UAstroNotificationToastWidget::UAstroNotificationToastWidget() {
    this->bWidgetShouldRemainPresented = false;
    this->MaxLifetime = 5.00f;
}

