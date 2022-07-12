#pragma once
#include "CoreMinimal.h"
#include "AstroGameMenuSpatialWindow.h"
#include "AstroGameMenuSubPaneWidget.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UAstroGameMenuSubPaneWidget : public UAstroGameMenuSpatialWindow {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFullScreen;
    
    UAstroGameMenuSubPaneWidget();
    UFUNCTION(BlueprintImplementableEvent)
    void NavigatedAwayFrom(bool isNavigateBack);
    
    UFUNCTION(BlueprintImplementableEvent)
    void MenuBeingClosed();
    
};

