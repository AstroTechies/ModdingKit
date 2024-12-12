#include "ButtonNavigationGridComponent.h"
#include "Components/InputComponent.h"

UButtonNavigationGridComponent::UButtonNavigationGridComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->InitialSelectedRow = 0;
    this->InitialSelectedColumn = 0;
    this->bAutoClickAndBounceBack = false;
    this->AnalogThreshold = 0.50f;
    this->InputComponent = CreateDefaultSubobject<UInputComponent>(TEXT("ButtonNavigationInputComponent"));
}

void UButtonNavigationGridComponent::SetSelectedGridCell(int32 row, int32 column) {
}

void UButtonNavigationGridComponent::SetSelectedButton(UButtonComponent* Button) {
}

void UButtonNavigationGridComponent::ResetGrid(int32 rows, int32 columns) {
}

void UButtonNavigationGridComponent::PushInputFocus(APlayerController* Controller) {
}

void UButtonNavigationGridComponent::PopInputFocus(APlayerController* Controller) {
}

void UButtonNavigationGridComponent::NavigateUp() {
}

void UButtonNavigationGridComponent::NavigateRight() {
}

void UButtonNavigationGridComponent::NavigateLeft() {
}

void UButtonNavigationGridComponent::NavigateDown() {
}

void UButtonNavigationGridComponent::Confirm() {
}

void UButtonNavigationGridComponent::AnalogVertical(float Y) {
}

void UButtonNavigationGridComponent::AnalogHorizontal(float X) {
}

void UButtonNavigationGridComponent::AddButton(UButtonComponent* Button, int32 row, int32 column) {
}


