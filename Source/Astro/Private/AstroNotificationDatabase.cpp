#include "AstroNotificationDatabase.h"

UAstroNotificationDatabase::UAstroNotificationDatabase() {
    this->TagNotificationQueueDisplayFrequency = 0.00f;
    this->UnlockNotificationQueueDisplayFrequency = 0.00f;
    this->ToastNotificationQueueDisplayFrequency = 0.00f;
    this->SuitUnlockNotifIconColor = EAstroColor::None;
    this->SuitUnlockNotifIcon = NULL;
    this->VisorUnlockNotifIconColor = EAstroColor::None;
    this->VisorUnlockNotifIcon = NULL;
    this->BundleUnlockNotifIconColor = EAstroColor::None;
    this->BundleUnlockNotifIcon = NULL;
    this->MissionObjectiveProgressNotifIcon = NULL;
    this->PaletteUnlockNotifIconColor = EAstroColor::None;
    this->PaletteUnlockNotifIcon = NULL;
    this->HatUnlockNotifIconColor = EAstroColor::None;
    this->HatUnlockNotifIcon = NULL;
    this->MaskUnlockNotifIconColor = EAstroColor::None;
    this->MaskUnlockNotifIcon = NULL;
    this->PhotoFilterUnlockNotifIconColor = EAstroColor::None;
    this->PhotoFilterUnlockNotifIcon = NULL;
    this->CarePackageIcon = NULL;
    this->AstroNotificationTagWidgetClass = NULL;
    this->AstroNotificationUnlockWidgetClass = NULL;
    this->AstroNotificationToastWidgetClass = NULL;
}

