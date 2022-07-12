#pragma once
#include "CoreMinimal.h"
#include "CameraModifierComponent.h"
#include "SimpleCollisionModifierComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class USimpleCollisionModifierComponent : public UCameraModifierComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CollisionSphereRadius;
    
    USimpleCollisionModifierComponent();
};

