#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "CameraContextSignalDelegate.h"
#include "CameraContext.generated.h"

class UCustomCameraRigComponent;

UCLASS(Blueprintable, DefaultToInstanced)
class UCameraContext : public UObject
{
    GENERATED_BODY()
public:
    UPROPERTY()
    FCameraContextSignal OnOwningRigDestroyed;

    UPROPERTY(Export, Transient)
    UCustomCameraRigComponent *OwningComponent;

    UPROPERTY()
    uint8 Priority;

    UCameraContext();
};
