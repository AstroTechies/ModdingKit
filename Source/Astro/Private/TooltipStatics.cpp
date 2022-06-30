#include "TooltipStatics.h"

class AActor;
class UTooltipComponent;

UTooltipComponent* UTooltipStatics::GetDefaultTooltipComponentForActor(AActor* TooltipOwner) {
    return NULL;
}

FTooltipWidgetDisplayData UTooltipStatics::DuplicateTooltipDisplayDataAndAppendInteractionPrompts(FTooltipWidgetDisplayData DataToCopy, const TArray<FInteractionPromptEntryData>& InteractionPromptDataToAdd) {
    return FTooltipWidgetDisplayData{};
}

UTooltipStatics::UTooltipStatics() {
}

