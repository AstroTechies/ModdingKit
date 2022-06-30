#pragma once
#include "CoreMinimal.h"
#include "CameraFacingWidgetComponent.h"
#include "PopupBadgeWidgetComponent.generated.h"

class UAstroPopupBadgeWidget;

UCLASS(Blueprintable, EditInlineNew, meta = (BlueprintSpawnableComponent))
class UPopupBadgeWidgetComponent : public UCameraFacingWidgetComponent
{
    GENERATED_BODY()
public:
protected:
    UPROPERTY(Export, Transient)
    UAstroPopupBadgeWidget *PopupBadgeWidget;

public:
    UPopupBadgeWidgetComponent();
};
