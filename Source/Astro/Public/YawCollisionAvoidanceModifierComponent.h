#pragma once
#include "CoreMinimal.h"
#include "CameraModifierComponent.h"
#include "YawCollisionAvoidanceModifierComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UYawCollisionAvoidanceModifierComponent : public UCameraModifierComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WhiskerCastSize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float VelocityScaleDivisor;
    
    UYawCollisionAvoidanceModifierComponent(const FObjectInitializer& ObjectInitializer);

};

