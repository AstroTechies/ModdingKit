#pragma once
#include "CoreMinimal.h"
#include "CustomGravityVolumeComponent.h"
#include "FixedGravityVolumeComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UFixedGravityVolumeComponent : public UCustomGravityVolumeComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BoxExtent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bApplyGravityUpward;
    
public:
    UFixedGravityVolumeComponent();
};

