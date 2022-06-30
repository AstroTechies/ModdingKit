#pragma once
#include "CoreMinimal.h"
#include "NearbyTetherAttachPoint.generated.h"

class UTetherAttachComponent;

USTRUCT()
struct FNearbyTetherAttachPoint {
    GENERATED_BODY()
public:
    UPROPERTY(Export)
    UTetherAttachComponent* NearbyTetherAttachComponent;
    
    ASTRO_API FNearbyTetherAttachPoint();
};

