#include "AstroPlayMontageTask.h"

class UAnimMontage;
class UAstroAction;
class UAstroPlayMontageTask;

void UAstroPlayMontageTask::RouteSingleAnimCustomNotify(FName NotifyName) {
}

void UAstroPlayMontageTask::OnMontageEnded(UAnimMontage* Montage, bool bInterrupted) {
}

void UAstroPlayMontageTask::OnAnimInitialized() {
}

UAstroPlayMontageTask* UAstroPlayMontageTask::CreateAstroPlayMontageTask(UAstroAction* OwningAction, FName TaskInstanceName, UAnimMontage* Montage, float PlayRate, FName StartSection) {
    return NULL;
}

UAstroPlayMontageTask::UAstroPlayMontageTask(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

