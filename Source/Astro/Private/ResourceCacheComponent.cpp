#include "ResourceCacheComponent.h"
#include "Templates/SubclassOf.h"

UResourceCacheComponent::UResourceCacheComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->DeformEventReceiver = NULL;
}

void UResourceCacheComponent::SwapResources(TSubclassOf<UItemType> MineralType) {
}

void UResourceCacheComponent::StoreResource(TSubclassOf<UItemType> MineralType, int32 Amount) {
}

void UResourceCacheComponent::OnAcceptResource(TSubclassOf<UItemType> Type, int32 Amount) {
}

AAstroCharacter* UResourceCacheComponent::GetCharacter() {
    return NULL;
}

void UResourceCacheComponent::CacheResources() {
}

bool UResourceCacheComponent::ApplyPower(float Amount) {
    return false;
}

bool UResourceCacheComponent::ApplyOxygen(int32 Amount) {
    return false;
}


