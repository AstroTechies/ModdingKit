#pragma once
#include "CoreMinimal.h"
#include "CustomGravityVolumeComponent.h"
#include "SphericalGravityVolumeComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API USphericalGravityVolumeComponent : public UCustomGravityVolumeComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SphereRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bApplyGravityOutward;
    
public:
    USphericalGravityVolumeComponent();
};

