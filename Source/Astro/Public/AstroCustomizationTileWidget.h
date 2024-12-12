#pragma once
#include "CoreMinimal.h"
#include "AstroInteractableTileWidget.h"
#include "AstroCustomizationTileWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ASTRO_API UAstroCustomizationTileWidget : public UAstroInteractableTileWidget {
    GENERATED_BODY()
public:
    UAstroCustomizationTileWidget();

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UpdateTileState();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Setup();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Sanitize();
    
protected:
    UFUNCTION(BlueprintCallable)
    void AsyncLoadSoftReferences();
    
};

