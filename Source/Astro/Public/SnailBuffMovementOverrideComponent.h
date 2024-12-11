#pragma once
#include "CoreMinimal.h"
#include "AstroCharacterMovementOverrideComponent.h"
#include "SnailBuffMovementOverrideComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API USnailBuffMovementOverrideComponent : public UAstroCharacterMovementOverrideComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AddedSprintMaxSpeedScalar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AddedJumpImpulse;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AddedBoostImpulse;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AddedJumpImpulseScalar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bIgnoreCarryEncumbrance: 1;
    
    USnailBuffMovementOverrideComponent(const FObjectInitializer& ObjectInitializer);

};

