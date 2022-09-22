#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=GameplayTasks -ObjectName=GameplayTask -FallbackName=GameplayTask
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Transform -FallbackName=Transform
#include "GameplayTask.h"
#include "AstroInterpolateItemTask.generated.h"

class UCurveFloat;
class UAstroInterpolateItemTask;
class UAstroAction;
class APhysicalItem;

UCLASS(Blueprintable)
class ASTRO_API UAstroInterpolateItemTask : public UGameplayTask {
    GENERATED_BODY()
public:
    UAstroInterpolateItemTask();
    UFUNCTION()
    void OnTargetItemMotionStateChanged();
    
    UFUNCTION(BlueprintCallable)
    static UAstroInterpolateItemTask* CreateAstroInterpolateItemTask(UAstroAction* OwningAction, FName TaskInstanceName, APhysicalItem* ItemToInterpolate, FTransform TargetTransform, float InterpolationDuration, bool bMaintainAttachmentDuringMovement, UCurveFloat* OptionalInterpolationProgressCurve);
    
};

