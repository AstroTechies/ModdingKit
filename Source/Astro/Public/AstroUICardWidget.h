#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "InputRespondingWidgetBase.h"
#include "AstroUICardWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ASTRO_API UAstroUICardWidget : public UInputRespondingWidgetBase {
    GENERATED_BODY()
public:
    UAstroUICardWidget();

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    FVector2D GetUICardScreenPosOffset();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    FVector2D GetUICardRenderSize();
    
};

