#include "UseToDiscoverItem.h"
#include "SingleUseConsumableComponent.h"

void AUseToDiscoverItem::OnUsed() {
}

AUseToDiscoverItem::AUseToDiscoverItem() {
    this->ItemTypeDiscoveredOnUse = NULL;
    this->ConsumableComponent = CreateDefaultSubobject<USingleUseConsumableComponent>(TEXT("ConsumableComponent"));
}

