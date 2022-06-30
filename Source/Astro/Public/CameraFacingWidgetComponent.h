#pragma once
#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "CameraFacingWidgetComponent.generated.h"

class USceneComponent;

UCLASS(Blueprintable, EditInlineNew, meta = (BlueprintSpawnableComponent))
class UCameraFacingWidgetComponent : public UWidgetComponent
{
    GENERATED_BODY()
public:
protected:
    UPROPERTY(Export)
    USceneComponent *WorldPositioningAnchor;

public:
    UCameraFacingWidgetComponent();
};
