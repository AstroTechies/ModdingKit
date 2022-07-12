#pragma once
#include "CoreMinimal.h"
#include "CameraModifierComponent.h"
#include "FixedVerticalOffsetModifierComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UFixedVerticalOffsetModifierComponent : public UCameraModifierComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float UpperLimit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LowerLimit;
    
    UFixedVerticalOffsetModifierComponent();
};

