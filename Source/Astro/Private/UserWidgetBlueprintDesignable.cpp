#include "UserWidgetBlueprintDesignable.h"

UUserWidgetBlueprintDesignable::UUserWidgetBlueprintDesignable() : UUserWidget(FObjectInitializer::Get()) {
}


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


