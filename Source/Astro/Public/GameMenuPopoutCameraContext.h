#pragma once
#include "CoreMinimal.h"
#include "CameraContext.h"
#include "GameMenuPopoutCameraContext.generated.h"

class APlayController;

UCLASS(Blueprintable, Blueprintable)
class UGameMenuPopoutCameraContext : public UCameraContext
{
    GENERATED_BODY()
public:
    UPROPERTY(Transient)
    APlayController *Controller;

    UGameMenuPopoutCameraContext();
};
