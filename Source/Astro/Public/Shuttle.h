#pragma once
#include "CoreMinimal.h"
#include "VehicleBase.h"
#include "Shuttle.generated.h"

UCLASS(Blueprintable)
class ASTRO_API AShuttle : public AVehicleBase {
    GENERATED_BODY()
public:
    AShuttle(const FObjectInitializer& ObjectInitializer);

};

