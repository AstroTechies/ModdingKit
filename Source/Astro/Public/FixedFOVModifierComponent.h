#pragma once
#include "CoreMinimal.h"
#include "CameraModifierComponent.h"
#include "FixedFOVModifierComponent.generated.h"

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class UFixedFOVModifierComponent : public UCameraModifierComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float FOV;

    UFixedFOVModifierComponent();
};
