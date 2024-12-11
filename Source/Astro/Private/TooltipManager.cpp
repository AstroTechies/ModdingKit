#include "TooltipManager.h"

UTooltipManager::UTooltipManager(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ExclusiveExpansionTooltip = NULL;
    this->CursorOverTooltip = NULL;
    this->AllTooltipsDisabled = false;
    this->BelongsToLocalController = false;
}

void UTooltipManager::OnTooltipPrimitiveEndCursorOver(UPrimitiveComponent* TooltipPrimitive) {
}

void UTooltipManager::OnTooltipPrimitiveBeginCursorOver(UPrimitiveComponent* TooltipPrimitive) {
}

void UTooltipManager::OnExclusiveExpansionTooltipOverrideChanged() {
}


