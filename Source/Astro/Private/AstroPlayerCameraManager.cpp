#include "AstroPlayerCameraManager.h"

AAstroPlayerCameraManager::AAstroPlayerCameraManager(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->DefaultModifiers.AddDefaulted(1);
    this->bClientSimulatingViewTarget = true;
}

void AAstroPlayerCameraManager::PopAllCameraContexts(UCameraContext* Context) {
}


