#pragma once
#include "CoreMinimal.h"
#include "EAstroGameMenuTutorialSlideDeckKey.h"
#include "UserWidgetBlueprintDesignable.h"
#include "EAstroGameMenuTutoriaSlideCardKey.h"
#include "AstropediaCarouselWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ASTRO_API UAstropediaCarouselWidget : public UUserWidgetBlueprintDesignable {
    GENERATED_BODY()
public:
    UAstropediaCarouselWidget();
    UFUNCTION(BlueprintImplementableEvent)
    void InitializeAstropedia(EAstroGameMenuTutorialSlideDeckKey deck, EAstroGameMenuTutoriaSlideCardKey card);
    
};

