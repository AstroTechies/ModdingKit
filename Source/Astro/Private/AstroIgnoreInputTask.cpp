#include "AstroIgnoreInputTask.h"

class UAstroAction;
class UAstroIgnoreInputTask;

UAstroIgnoreInputTask* UAstroIgnoreInputTask::CreateAstroIgnoreInputTask(UAstroAction* OwningAction, FName TaskInstanceName, bool bShouldIgnoreMoveInput, bool bShouldIgnoreLookInput) {
    return NULL;
}

UAstroIgnoreInputTask::UAstroIgnoreInputTask() : UGameplayTask(FObjectInitializer()) {
}

