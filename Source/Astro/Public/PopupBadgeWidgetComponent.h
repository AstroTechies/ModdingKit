#pragma once
#include "CoreMinimal.h"
#include "CameraFacingWidgetComponent.h"
#include "PopupBadgeWidgetComponent.generated.h"

class UAstroPopupBadgeWidget;

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UPopupBadgeWidgetComponent : public UCameraFacingWidgetComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UAstroPopupBadgeWidget* PopupBadgeWidget;
    
public:
    UPopupBadgeWidgetComponent();
};

