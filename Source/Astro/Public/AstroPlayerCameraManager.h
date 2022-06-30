#pragma once
#include "CoreMinimal.h"
#include "Camera/PlayerCameraManager.h"
#include "AstroPlayerCameraManager.generated.h"

class UCameraContext;

UCLASS(Blueprintable, NonTransient)
class AAstroPlayerCameraManager : public APlayerCameraManager
{
    GENERATED_BODY()
public:
protected:
    UPROPERTY(Export, Transient)
    TArray<UCameraContext *> ContextStack;

public:
    AAstroPlayerCameraManager();
    UFUNCTION()
    void PopAllCameraContexts(UCameraContext *Context);
};
