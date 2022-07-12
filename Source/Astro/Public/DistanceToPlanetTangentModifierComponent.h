#pragma once
#include "CoreMinimal.h"
#include "CameraModifierComponent.h"
#include "DistanceToPlanetTangentModifierComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UDistanceToPlanetTangentModifierComponent : public UCameraModifierComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TangentOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LimitDistance;
    
    UDistanceToPlanetTangentModifierComponent();
};

