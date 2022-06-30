#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UserWidgetSignalDelegate.h"
#include "TileInputSignalDelegate.h"
#include "AstroInteractableTileWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ASTRO_API UAstroInteractableTileWidget : public UUserWidget
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintCallable)
    FUserWidgetSignal OnTileAddedToFocusPath;

    UPROPERTY(BlueprintAssignable, BlueprintCallable)
    FUserWidgetSignal OnTileRemovedFromFocusPath;

    UPROPERTY(BlueprintAssignable, BlueprintCallable)
    FTileInputSignal OnTilePressed;

    UPROPERTY(BlueprintAssignable, BlueprintCallable)
    FTileInputSignal OnTileReleased;

    UPROPERTY(BlueprintAssignable, BlueprintCallable)
    FUserWidgetSignal OnTileHovered;

    UPROPERTY(BlueprintAssignable, BlueprintCallable)
    FUserWidgetSignal OnTileUnhovered;

    UAstroInteractableTileWidget();
};
