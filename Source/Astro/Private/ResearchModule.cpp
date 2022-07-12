#include "ResearchModule.h"
#include "PowerComponent.h"
#include "ActorResearchComponent.h"
#include "AdaptiveTickComponent.h"

AResearchModule::AResearchModule() {
    this->ActorResearchComponent = CreateDefaultSubobject<UActorResearchComponent>(TEXT("Research"));
    this->PowerComponent = CreateDefaultSubobject<UPowerComponent>(TEXT("PowerComponent"));
    this->AdaptiveTickComponent = CreateDefaultSubobject<UAdaptiveTickComponent>(TEXT("AdaptiveTick"));
}

