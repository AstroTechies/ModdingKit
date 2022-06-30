#include "NavpointManagerActor.h"
#include "NavpointManager.h"

ANavpointManagerActor::ANavpointManagerActor() {
    this->NavpointManager = CreateDefaultSubobject<UNavpointManager>(TEXT("NavpointManager"));
}

