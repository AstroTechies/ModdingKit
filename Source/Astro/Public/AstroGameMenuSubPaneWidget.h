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
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool BackNavigationRequiresConfirmation;
    
    UAstroGameMenuSubPaneWidget();

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void NavigatedAwayFrom(bool isNavigateBack);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void MenuBeingClosed();
    
};

