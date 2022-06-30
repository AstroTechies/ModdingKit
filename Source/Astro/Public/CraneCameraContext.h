#pragma once
#include "CoreMinimal.h"
#include "CameraContext.h"
#include "CraneCameraContext.generated.h"

UCLASS(Blueprintable, Blueprintable)
class UCraneCameraContext : public UCameraContext
{
    GENERATED_BODY()
public:
    UCraneCameraContext();
};
