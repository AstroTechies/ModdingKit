#include "AstroPlayMontageTask.h"

UAstroPlayMontageTask::UAstroPlayMontageTask() : UGameplayTask(FObjectInitializer()) {
}

void UAstroPlayMontageTask::RouteSingleAnimCustomNotify(FName NotifyName) {
}

void UAstroPlayMontageTask::OnMontageEnded(UAnimMontage* Montage, bool bInterrupted) {
}

void UAstroPlayMontageTask::OnAnimInitialized() {
}

UAstroPlayMontageTask* UAstroPlayMontageTask::CreateAstroPlayMontageTask(UAstroAction* OwningAction, FName TaskInstanceName, UAnimMontage* Montage, float PlayRate, FName StartSection) {
    return NULL;
}


