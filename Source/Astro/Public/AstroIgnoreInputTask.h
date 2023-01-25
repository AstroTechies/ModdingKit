#pragma once
#include "CoreMinimal.h"
#include "GameplayTask.h"
#include "AstroIgnoreInputTask.generated.h"

class UAstroAction;
class UAstroIgnoreInputTask;

UCLASS(Blueprintable)
class ASTRO_API UAstroIgnoreInputTask : public UGameplayTask {
    GENERATED_BODY()
public:
    UAstroIgnoreInputTask();
    UFUNCTION(BlueprintCallable)
    static UAstroIgnoreInputTask* CreateAstroIgnoreInputTask(UAstroAction* OwningAction, FName TaskInstanceName, bool bShouldIgnoreMoveInput, bool bShouldIgnoreLookInput);
    
};

