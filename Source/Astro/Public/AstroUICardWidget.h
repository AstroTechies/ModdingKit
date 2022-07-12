#pragma once
#include "CoreMinimal.h"
#include "InputRespondingWidgetBase.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector2D -FallbackName=Vector2D
#include "AstroUICardWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ASTRO_API UAstroUICardWidget : public UInputRespondingWidgetBase {
    GENERATED_BODY()
public:
    UAstroUICardWidget();
    UFUNCTION(BlueprintImplementableEvent, BlueprintPure)
    FVector2D GetUICardScreenPosOffset();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    FVector2D GetUICardRenderSize();
    
};

