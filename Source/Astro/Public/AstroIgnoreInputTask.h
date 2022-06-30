#pragma once
#include "CoreMinimal.h"
#include "GameplayTask.h"
#include "AstroIgnoreInputTask.generated.h"

class UAstroIgnoreInputTask;
class UAstroAction;

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API UAstroIgnoreInputTask : public UGameplayTask
{
    GENERATED_BODY()
public:
    UAstroIgnoreInputTask(const FObjectInitializer &ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    static UAstroIgnoreInputTask *CreateAstroIgnoreInputTask(UAstroAction *OwningAction, FName TaskInstanceName, bool bShouldIgnoreMoveInput, bool bShouldIgnoreLookInput);
};
