#pragma once
#include "CoreMinimal.h"
#include "CustomGravityVolumeComponent.h"
#include "CylindricalGravityVolumeComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UCylindricalGravityVolumeComponent : public UCustomGravityVolumeComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CylinderRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CylinderHeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bApplyGravityOutward;
    
public:
    UCylindricalGravityVolumeComponent(const FObjectInitializer& ObjectInitializer);

};

