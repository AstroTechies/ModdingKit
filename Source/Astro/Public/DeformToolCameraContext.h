#pragma once
#include "CoreMinimal.h"
#include "CameraContext.h"
#include "DeformToolCameraContext.generated.h"

class ADeformTool;

UCLASS(Blueprintable, Blueprintable)
class UDeformToolCameraContext : public UCameraContext
{
    GENERATED_BODY()
public:
    UPROPERTY()
    ADeformTool *DeformTool;

    UDeformToolCameraContext();
};
