#pragma once
#include "CoreMinimal.h"
#include "ControlPanel.h"
#include "SplitterControlPanel.generated.h"

class UCrackableActorComponent;

UCLASS(Abstract, Blueprintable)
class ASTRO_API ASplitterControlPanel : public AControlPanel {
    GENERATED_BODY()
public:
    ASplitterControlPanel();
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ProcessSplitterControlPanelInput();
    
private:
    UFUNCTION(BlueprintCallable)
    void HandleFullyCrackedOrClosed(UCrackableActorComponent* InCrackableActorComponent, bool bIsCracked);
    
    UFUNCTION(BlueprintCallable)
    void HandleCrackedChanged(UCrackableActorComponent* InCrackableActorComponent, bool bIsCracked);
    
};

