#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
#include "AstroCharacterMovementOverrideComponent.generated.h"

UCLASS(Abstract, Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UAstroCharacterMovementOverrideComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UAstroCharacterMovementOverrideComponent();
    UFUNCTION(BlueprintCallable)
    void TryRegisterOverride(bool bRegister);
    
};

