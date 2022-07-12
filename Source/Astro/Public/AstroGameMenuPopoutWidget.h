#pragma once
#include "CoreMinimal.h"
#include "AstroGameMenuSpatialWindow.h"
#include "AstroGameMenuPopoutWidget.generated.h"

class UPanelWidget;
class UAstroGameMenuPopoutWidgetContentsBase;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UAstroGameMenuPopoutWidget : public UAstroGameMenuSpatialWindow {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UAstroGameMenuPopoutWidgetContentsBase* PopoutContents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bMouseOverWidget: 1;
    
public:
    UAstroGameMenuPopoutWidget();
    UFUNCTION(BlueprintImplementableEvent)
    UPanelWidget* GetPopoutPanelWrapper() const;
    
    UFUNCTION(BlueprintImplementableEvent)
    UPanelWidget* GetPopoutOutermostContainer() const;
    
    UFUNCTION(BlueprintImplementableEvent)
    UPanelWidget* GetPopoutContentsWrapper() const;
    
};

