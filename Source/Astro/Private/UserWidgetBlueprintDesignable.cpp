#include "UserWidgetBlueprintDesignable.h"


void UUserWidgetBlueprintDesignable::PostLayoutWidget_Implementation() {
}

void UUserWidgetBlueprintDesignable::OnSynchronizeProperties_Implementation() {
}

bool UUserWidgetBlueprintDesignable::LayoutWidget_Implementation() {
    return false;
}

bool UUserWidgetBlueprintDesignable::GetStylingDataSetupComplete() {
    return false;
}

UUserWidgetBlueprintDesignable::UUserWidgetBlueprintDesignable() : UUserWidget(FObjectInitializer::Get()) {
}

