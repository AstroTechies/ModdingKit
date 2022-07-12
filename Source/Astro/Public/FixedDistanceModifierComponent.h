#pragma once
#include "CoreMinimal.h"
#include "CameraModifierComponent.h"
#include "FixedDistanceModifierComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UFixedDistanceModifierComponent : public UCameraModifierComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Distance;
    
    UFixedDistanceModifierComponent();
};

