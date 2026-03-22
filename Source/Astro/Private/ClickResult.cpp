#include "ClickResult.h"

FClickResult::FClickResult() {
    this->PrimaryComponent = NULL;
    this->PrimaryHoverComponent = NULL;
    this->TracedActor = NULL;
    this->PrimaryActor = NULL;
    this->SecondaryActor = NULL;
    this->TertiaryActor = NULL;
    this->PrimaryViewActor = NULL;
    this->SecondaryViewActor = NULL;
    this->TertiaryViewActor = NULL;
    this->PrimaryBehavior = EClickBehavior::None;
    this->SecondaryBehavior = EClickBehavior::None;
    this->TertiaryBehavior = EClickBehavior::None;
    this->PrimaryBehaviorMetadata = 0;
    this->bClickCaptured = false;
    this->bSuppressQuickSelect = false;
    this->bSlowVirtualCursorOnHover = false;
    this->bSwapDisallowed = false;
}

