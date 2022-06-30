#include "ResearchPointGrantItem.h"
#include "ActorResearchPointGrantComponent.h"

void AResearchPointGrantItem::OnUsed() {
}

AResearchPointGrantItem::AResearchPointGrantItem() {
    this->ResearchPointGrantComponent = CreateDefaultSubobject<UActorResearchPointGrantComponent>(TEXT("ActorResearchPointGrant"));
}

