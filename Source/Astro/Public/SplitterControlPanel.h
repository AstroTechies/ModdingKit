#pragma once
#include "CoreMinimal.h"
#include "ControlPanel.h"
#include "SplitterControlPanel.generated.h"

class UCrackableActorComponent;

UCLASS(Blueprintable, Abstract)
class ASTRO_API ASplitterControlPanel : public AControlPanel
{
    GENERATED_BODY()
public:
    ASplitterControlPanel();

protected:
    UFUNCTION(BlueprintImplementableEvent)
    void ProcessSplitterControlPanelInput();

private:
    UFUNCTION()
    void HandleFullyCrackedOrClosed(UCrackableActorComponent *InCrackableActorComponent, bool bIsCracked);

    UFUNCTION()
    void HandleCrackedChanged(UCrackableActorComponent *InCrackableActorComponent, bool bIsCracked);
};
