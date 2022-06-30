#pragma once
#include "CoreMinimal.h"
#include "CameraContext.h"
#include "BackpackCameraContext.generated.h"

class APlayController;

UCLASS(Blueprintable, Blueprintable)
class UBackpackCameraContext : public UCameraContext
{
    GENERATED_BODY()
public:
    UPROPERTY(Transient)
    APlayController *Controller;

    UBackpackCameraContext();
};
