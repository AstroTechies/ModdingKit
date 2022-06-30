#include "ButtonInputManagerComponent.h"
#include "Components/InputComponent.h"

class APlayerController;
class UButtonComponent;

void UButtonInputManagerComponent::PushInputFocus(APlayerController* Controller) {
}

void UButtonInputManagerComponent::PopInputFocus(APlayerController* Controller) {
}

void UButtonInputManagerComponent::Confirm() {
}

void UButtonInputManagerComponent::Cancel() {
}

void UButtonInputManagerComponent::AddButton(UButtonComponent* Button, TEnumAsByte<EButtonInput> InputType) {
}

UButtonInputManagerComponent::UButtonInputManagerComponent() {
    this->InputComponent = CreateDefaultSubobject<UInputComponent>(TEXT("ButtonInputManagerInputComponent"));
}

