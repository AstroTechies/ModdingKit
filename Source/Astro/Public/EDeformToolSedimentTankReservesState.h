#pragma once
#include "CoreMinimal.h"
#include "EDeformToolSedimentTankReservesState.generated.h"

UENUM(BlueprintType)
enum class EDeformToolSedimentTankReservesState : uint8 {
    NoReserves,
    ReservesEmpty,
    ReservesPartiallyFull,
    ReservesFull,
};

