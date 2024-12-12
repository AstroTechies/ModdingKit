#pragma once
#include "CoreMinimal.h"
#include "CameraModifierComponent.h"
#include "VelocityPitchModifierComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UVelocityPitchModifierComponent : public UCameraModifierComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float VelocitySmoothing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SaturationSpeed;
    
    UVelocityPitchModifierComponent(const FObjectInitializer& ObjectInitializer);

};

