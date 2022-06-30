#pragma once
#include "CoreMinimal.h"
#include "CameraContext.h"
#include "StoreMenuCameraContext.generated.h"

class APlayController;

UCLASS(Blueprintable, Blueprintable)
class UStoreMenuCameraContext : public UCameraContext
{
    GENERATED_BODY()
public:
    UPROPERTY(Transient)
    APlayController *Controller;

    UStoreMenuCameraContext();
};
