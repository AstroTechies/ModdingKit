#include "ButtonInputManagerComponent.h"
#include "Components/InputComponent.h"

UButtonInputManagerComponent::UButtonInputManagerComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->InputComponent = CreateDefaultSubobject<UInputComponent>(TEXT("ButtonInputManagerInputComponent"));
}

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


