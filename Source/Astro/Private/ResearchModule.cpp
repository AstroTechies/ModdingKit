#include "ResearchModule.h"
#include "ActorResearchComponent.h"
#include "AdaptiveTickComponent.h"
#include "PowerComponent.h"

AResearchModule::AResearchModule() {
    this->ActorResearchComponent = CreateDefaultSubobject<UActorResearchComponent>(TEXT("Research"));
    this->PowerComponent = CreateDefaultSubobject<UPowerComponent>(TEXT("PowerComponent"));
    this->AdaptiveTickComponent = CreateDefaultSubobject<UAdaptiveTickComponent>(TEXT("AdaptiveTick"));
}

