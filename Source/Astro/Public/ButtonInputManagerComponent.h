#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EButtonInput.h"
#include "ButtonInputManagerComponent.generated.h"

class UInputComponent;
class UButtonComponent;
class APlayerController;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UButtonInputManagerComponent : public UActorComponent
{
    GENERATED_BODY()
public:
private:
    UPROPERTY(Export, Transient)
    TMap<int32, UButtonComponent *> Buttons;

    UPROPERTY(Export, Transient)
    UInputComponent *InputComponent;

public:
    UButtonInputManagerComponent();
    UFUNCTION(BlueprintCallable)
    void PushInputFocus(APlayerController *Controller);

    UFUNCTION(BlueprintCallable)
    void PopInputFocus(APlayerController *Controller);

private:
    UFUNCTION()
    void Confirm();

    UFUNCTION()
    void Cancel();

public:
    UFUNCTION(BlueprintCallable)
    void AddButton(UButtonComponent *Button, TEnumAsByte<EButtonInput> InputType);
};
