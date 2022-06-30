#pragma once
#include "CoreMinimal.h"
#include "CameraContext.h"
#include "ControlPanelCameraContext.generated.h"

UCLASS(Blueprintable, Blueprintable)
class UControlPanelCameraContext : public UCameraContext
{
    GENERATED_BODY()
public:
    UControlPanelCameraContext();
};
