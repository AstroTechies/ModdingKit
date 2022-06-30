#pragma once
#include "CoreMinimal.h"
#include "CameraModifierComponent.h"
#include "SimpleCollisionModifierComponent.generated.h"

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class USimpleCollisionModifierComponent : public UCameraModifierComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    float CollisionSphereRadius;

    USimpleCollisionModifierComponent();
};
