#pragma once
#include "CoreMinimal.h"
#include "ControlPanel.h"
#include "GenericSliderControlPanel.generated.h"

class UCrackableActorComponent;

UCLASS(Abstract, Blueprintable)
class ASTRO_API AGenericSliderControlPanel : public AControlPanel {
    GENERATED_BODY()
public:
    AGenericSliderControlPanel(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ProcessSliderInput();
    
    UFUNCTION(BlueprintCallable)
    void OnSliderReleased();
    
    UFUNCTION(BlueprintCallable)
    void OnSliderClicked();
    
private:
    UFUNCTION(BlueprintCallable)
    void HandleCrackedChanged(UCrackableActorComponent* InCrackableActorComponent, bool bIsCracked);
    
};

