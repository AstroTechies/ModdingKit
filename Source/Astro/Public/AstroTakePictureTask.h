#pragma once
#include "CoreMinimal.h"
#include "GameplayTask.h"
#include "AstroTakePictureTask.generated.h"

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API UAstroTakePictureTask : public UGameplayTask
{
    GENERATED_BODY()
public:
    UAstroTakePictureTask(const FObjectInitializer &ObjectInitializer);

protected:
    UFUNCTION()
    void OnPhotoWidgetClosed();

    UFUNCTION()
    void DisplayPhotoWidget();
};
