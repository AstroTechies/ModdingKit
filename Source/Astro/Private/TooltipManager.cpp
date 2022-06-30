#include "TooltipManager.h"

class UPrimitiveComponent;

void UTooltipManager::OnTooltipPrimitiveEndCursorOver(UPrimitiveComponent* TooltipPrimitive) {
}

void UTooltipManager::OnTooltipPrimitiveBeginCursorOver(UPrimitiveComponent* TooltipPrimitive) {
}

void UTooltipManager::OnExclusiveExpansionTooltipOverrideChanged() {
}

UTooltipManager::UTooltipManager() {
    this->ExclusiveExpansionTooltip = NULL;
    this->CursorOverTooltip = NULL;
    this->AllTooltipsDisabled = false;
    this->BelongsToLocalController = false;
}

