#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "CameraFacingManager.generated.h"

class USceneComponent;

UCLASS(Blueprintable, Blueprintable)
class UCameraFacingManager : public UObject
{
    GENERATED_BODY()
public:
private:
    UPROPERTY(Export, Transient)
    TArray<USceneComponent *> SceneComponents;

public:
    UCameraFacingManager();
};
