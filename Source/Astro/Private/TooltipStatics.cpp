#include "TooltipStatics.h"

UTooltipStatics::UTooltipStatics() {
}

UTooltipComponent* UTooltipStatics::GetDefaultTooltipComponentForActor(AActor* TooltipOwner) {
    return NULL;
}

FTooltipWidgetDisplayData UTooltipStatics::DuplicateTooltipDisplayDataAndAppendInteractionPrompts(FTooltipWidgetDisplayData DataToCopy, const TArray<FInteractionPromptEntryData>& InteractionPromptDataToAdd) {
    return FTooltipWidgetDisplayData{};
}


