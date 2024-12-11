#include "ItemPadActor.h"

AItemPadActor::AItemPadActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->BaseLocation = NULL;
    this->OwnerComponent = NULL;
}

bool AItemPadActor::ShouldDestroyOnPickup_Implementation() {
    return false;
}


void AItemPadActor::OnOwnerDestroyed(AActor* deletingOwner) {
}


