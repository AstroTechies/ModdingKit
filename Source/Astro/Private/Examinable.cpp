#include "Examinable.h"

bool UExaminable::ValidateWithinExamineRange() {
    return false;
}

UExaminable::UExaminable() {
    this->AutoDismissRange = 1700.00f;
}

