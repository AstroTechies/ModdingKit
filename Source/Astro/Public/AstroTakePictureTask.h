#pragma once
#include "CoreMinimal.h"
#include "GameplayTask.h"
#include "GameplayTask.h"
#include "AstroTakePictureTask.generated.h"

UCLASS(Blueprintable)
class ASTRO_API UAstroTakePictureTask : public UGameplayTask {
    GENERATED_BODY()
public:
    UAstroTakePictureTask();
protected:
    UFUNCTION()
    void OnPhotoWidgetClosed();
    
    UFUNCTION()
    void DisplayPhotoWidget();
    
};

