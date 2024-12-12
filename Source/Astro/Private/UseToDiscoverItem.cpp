#include "UseToDiscoverItem.h"
#include "SingleUseConsumableComponent.h"

AUseToDiscoverItem::AUseToDiscoverItem(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ItemTypeDiscoveredOnUse = NULL;
    this->ConsumableComponent = CreateDefaultSubobject<USingleUseConsumableComponent>(TEXT("ConsumableComponent"));
}

void AUseToDiscoverItem::OnUsed() {
}


