#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AstroCharacterMovementOverrideComponent.generated.h"

UCLASS(Abstract, Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UAstroCharacterMovementOverrideComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UAstroCharacterMovementOverrideComponent();
    UFUNCTION(BlueprintCallable)
    void TryRegisterOverride(bool bRegister);
    
};

