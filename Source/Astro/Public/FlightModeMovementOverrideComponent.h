#pragma once
#include "CoreMinimal.h"
#include "AstroCharacterMovementOverrideComponent.h"
#include "FlightModeMovementOverrideComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UFlightModeMovementOverrideComponent : public UAstroCharacterMovementOverrideComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SpeedScalarOverride;
    
    UFlightModeMovementOverrideComponent(const FObjectInitializer& ObjectInitializer);

};

