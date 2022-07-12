#pragma once
#include "CoreMinimal.h"
#include "NearbyTetherAttachPoint.generated.h"

class UTetherAttachComponent;

USTRUCT(BlueprintType)
struct FNearbyTetherAttachPoint {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UTetherAttachComponent* NearbyTetherAttachComponent;
    
    ASTRO_API FNearbyTetherAttachPoint();
};

