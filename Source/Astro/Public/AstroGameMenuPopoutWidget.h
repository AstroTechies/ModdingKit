#pragma once
#include "CoreMinimal.h"
#include "AstroGameMenuSpatialWindow.h"
#include "AstroGameMenuPopoutWidget.generated.h"

class UAstroGameMenuPopoutWidgetContentsBase;
class UPanelWidget;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UAstroGameMenuPopoutWidget : public UAstroGameMenuSpatialWindow {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAstroGameMenuPopoutWidgetContentsBase* PopoutContents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bMouseOverWidget: 1;
    
public:
    UAstroGameMenuPopoutWidget();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    UPanelWidget* GetPopoutPanelWrapper() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    UPanelWidget* GetPopoutOutermostContainer() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    UPanelWidget* GetPopoutContentsWrapper() const;
    
};

