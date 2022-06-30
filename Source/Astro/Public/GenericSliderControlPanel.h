#pragma once
#include "CoreMinimal.h"
#include "ControlPanel.h"
#include "GenericSliderControlPanel.generated.h"

class UCrackableActorComponent;

UCLASS(Blueprintable, Abstract)
class ASTRO_API AGenericSliderControlPanel : public AControlPanel
{
    GENERATED_BODY()
public:
    AGenericSliderControlPanel();

protected:
    UFUNCTION(BlueprintImplementableEvent)
    void ProcessSliderInput();

    UFUNCTION(BlueprintCallable)
    void OnSliderReleased();

    UFUNCTION(BlueprintCallable)
    void OnSliderClicked();

private:
    UFUNCTION()
    void HandleCrackedChanged(UCrackableActorComponent *InCrackableActorComponent, bool bIsCracked);
};
