#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ButtonNavigationGridComponent.generated.h"

class UInputComponent;
class UButtonComponent;
class APlayerController;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class UButtonNavigationGridComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    uint32 InitialSelectedRow;

    UPROPERTY(EditAnywhere)
    uint32 InitialSelectedColumn;

    UPROPERTY(EditAnywhere)
    uint8 bAutoClickAndBounceBack : 1;

    UPROPERTY(EditAnywhere)
    float AnalogThreshold;

private:
    UPROPERTY(Export, Transient)
    TArray<UButtonComponent *> Buttons;

    UPROPERTY(Export, Transient)
    UInputComponent *InputComponent;

public:
    UButtonNavigationGridComponent();
    UFUNCTION(BlueprintCallable)
    void SetSelectedGridCell(int32 row, int32 column);

    UFUNCTION(BlueprintCallable)
    void SetSelectedButton(UButtonComponent *Button);

    UFUNCTION(BlueprintCallable)
    void ResetGrid(int32 rows, int32 columns);

    UFUNCTION(BlueprintCallable)
    void PushInputFocus(APlayerController *Controller);

    UFUNCTION(BlueprintCallable)
    void PopInputFocus(APlayerController *Controller);

private:
    UFUNCTION()
    void NavigateUp();

    UFUNCTION()
    void NavigateRight();

    UFUNCTION()
    void NavigateLeft();

    UFUNCTION()
    void NavigateDown();

    UFUNCTION()
    void Confirm();

    UFUNCTION()
    void AnalogVertical(float Y);

    UFUNCTION()
    void AnalogHorizontal(float X);

public:
    UFUNCTION(BlueprintCallable)
    void AddButton(UButtonComponent *Button, int32 row, int32 column);
};
