#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=GameplayTasks -ObjectName=GameplayTask -FallbackName=GameplayTask
#include "GameplayTask.h"
#include "AstroIgnoreInputTask.generated.h"

class UAstroIgnoreInputTask;
class UAstroAction;

UCLASS(Blueprintable)
class ASTRO_API UAstroIgnoreInputTask : public UGameplayTask {
    GENERATED_BODY()
public:
    UAstroIgnoreInputTask();
    UFUNCTION(BlueprintCallable)
    static UAstroIgnoreInputTask* CreateAstroIgnoreInputTask(UAstroAction* OwningAction, FName TaskInstanceName, bool bShouldIgnoreMoveInput, bool bShouldIgnoreLookInput);
    
};

