#include "PowerStatics.h"

class UObject;
class UPowerComponent;

void UPowerStatics::SetFreePower(bool Enable, UObject* WorldContextObject) {
}

TArray<UPowerComponent*> UPowerStatics::GetSlotActorPowerComponents(FSlotReference PowerSlot) {
    return TArray<UPowerComponent*>();
}

bool UPowerStatics::GetFreePower(const UObject* WorldContextObject) {
    return false;
}

UPowerStatics::UPowerStatics() {
}

