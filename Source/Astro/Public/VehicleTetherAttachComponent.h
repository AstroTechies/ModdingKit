#pragma once
#include "CoreMinimal.h"
#include "TetherAttachComponent.h"
#include "VehicleTetherAttachComponent.generated.h"

class UTetherNetwork;

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class ASTRO_API UVehicleTetherAttachComponent : public UTetherAttachComponent
{
    GENERATED_BODY()
public:
private:
    UPROPERTY(Export)
    UTetherAttachComponent *PreviousClosestTetherPost;

    UPROPERTY()
    UTetherNetwork *PreviousTetherNetwork;

public:
    UVehicleTetherAttachComponent();
};
