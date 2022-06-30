#pragma once
#include "CoreMinimal.h"
#include "InputRespondingWidgetBase.h"
#include "UObject/NoExportTypes.h"
#include "AstroUICardWidget.generated.h"

UCLASS(EditInlineNew)
class ASTRO_API UAstroUICardWidget : public UInputRespondingWidgetBase {
    GENERATED_BODY()
public:
    UAstroUICardWidget();
    UFUNCTION(BlueprintImplementableEvent, BlueprintPure)
    FVector2D GetUICardScreenPosOffset();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    FVector2D GetUICardRenderSize();
    
};

