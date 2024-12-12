#pragma once
#include "CoreMinimal.h"
#include "CameraModifierComponent.h"
#include "FrameTargetModifierComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UFrameTargetModifierComponent : public UCameraModifierComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HeightOffset;
    
    UFrameTargetModifierComponent(const FObjectInitializer& ObjectInitializer);

};

