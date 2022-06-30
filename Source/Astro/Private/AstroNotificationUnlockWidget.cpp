#include "AstroNotificationUnlockWidget.h"

void UAstroNotificationUnlockWidget::MarkNotificationForDestruction() {
}

UAstroNotificationUnlockWidget::UAstroNotificationUnlockWidget() {
    this->DriftIncrement = 60.00f;
    this->SpawningDriftOffset = 20.00f;
    this->MaxLifetime = 5.00f;
    this->MagicDriftSpeed = 8.10f;
}

