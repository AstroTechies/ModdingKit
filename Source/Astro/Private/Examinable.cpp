#include "Examinable.h"

UExaminable::UExaminable(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->AutoDismissRange = 1700.00f;
}

bool UExaminable::ValidateWithinExamineRange() {
    return false;
}


