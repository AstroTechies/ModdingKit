#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TileInputSignalDelegate.h"
#include "UserWidgetSignalDelegate.h"
#include "AstroInteractableTileWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ASTRO_API UAstroInteractableTileWidget : public UUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FUserWidgetSignal OnTileAddedToFocusPath;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FUserWidgetSignal OnTileRemovedFromFocusPath;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTileInputSignal OnTilePressed;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTileInputSignal OnTileReleased;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FUserWidgetSignal OnTileHovered;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FUserWidgetSignal OnTileUnhovered;
    
    UAstroInteractableTileWidget();
};

