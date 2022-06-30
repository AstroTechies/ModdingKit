#include "ItemPadActor.h"

class AActor;

bool AItemPadActor::ShouldDestroyOnPickup_Implementation() {
    return false;
}


void AItemPadActor::OnOwnerDestroyed(AActor* deletingOwner) {
}

AItemPadActor::AItemPadActor() {
    this->BaseLocation = NULL;
    this->OwnerComponent = NULL;
}

