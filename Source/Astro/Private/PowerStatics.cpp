#include "PowerStatics.h"

UPowerStatics::UPowerStatics() {
}

void UPowerStatics::SetFreePower(bool Enable, UObject* WorldContextObject) {
}

TArray<UPowerComponent*> UPowerStatics::GetSlotActorPowerComponents(FSlotReference PowerSlot) {
    return TArray<UPowerComponent*>();
}

bool UPowerStatics::GetFreePower(const UObject* WorldContextObject) {
    return false;
}


