#include "AstroStreamingPowerTickTaskManager.h"

UAstroStreamingPowerTickTaskManager::UAstroStreamingPowerTickTaskManager() {
    this->DependentDatumContainerTypes.AddDefaulted(4);
    this->StreamingPowerSystem = NULL;
}


