#pragma once
#include "CoreMinimal.h"
#include "CameraContext.h"
#include "MultitoolCameraContext.generated.h"

class UMultiTool;

UCLASS(Blueprintable, Blueprintable)
class UMultitoolCameraContext : public UCameraContext
{
    GENERATED_BODY()
public:
    UPROPERTY(Export)
    UMultiTool *MultiTool;

    UMultitoolCameraContext();
};
