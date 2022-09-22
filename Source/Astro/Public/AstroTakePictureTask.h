#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=GameplayTasks -ObjectName=GameplayTask -FallbackName=GameplayTask
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

