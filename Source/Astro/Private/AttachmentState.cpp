#include "AttachmentState.h"

FAttachmentState::FAttachmentState() {
    this->Actor = NULL;
    this->bExiting = false;
    this->bOwnerIsViewTargetWhileAttached = false;
    this->MovementMethod = EEnterExitMovementMethod::SnapToPosition;
}

