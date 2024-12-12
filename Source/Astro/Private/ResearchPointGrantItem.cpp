#include "ResearchPointGrantItem.h"
#include "ActorResearchPointGrantComponent.h"

AResearchPointGrantItem::AResearchPointGrantItem(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ResearchPointGrantComponent = CreateDefaultSubobject<UActorResearchPointGrantComponent>(TEXT("ActorResearchPointGrant"));
}

void AResearchPointGrantItem::OnUsed() {
}


