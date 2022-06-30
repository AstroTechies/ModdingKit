#pragma once
#include "CoreMinimal.h"
#include "AstroGameMenuSpatialWindow.h"
#include "AstroGameMenuPopoutWidget.generated.h"

class UAstroGameMenuPopoutWidgetContentsBase;
class UPanelWidget;

UCLASS(Blueprintable, Abstract, EditInlineNew)
class UAstroGameMenuPopoutWidget : public UAstroGameMenuSpatialWindow
{
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    UAstroGameMenuPopoutWidgetContentsBase *PopoutContents;

    UPROPERTY()
    uint8 bMouseOverWidget : 1;

public:
    UAstroGameMenuPopoutWidget();
    UFUNCTION(BlueprintImplementableEvent)
    UPanelWidget *GetPopoutPanelWrapper() const;

    UFUNCTION(BlueprintImplementableEvent)
    UPanelWidget *GetPopoutOutermostContainer() const;

    UFUNCTION(BlueprintImplementableEvent)
    UPanelWidget *GetPopoutContentsWrapper() const;
};
