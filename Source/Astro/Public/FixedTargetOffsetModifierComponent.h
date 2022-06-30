#pragma once
#include "CoreMinimal.h"
#include "CameraModifierComponent.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "FixedTargetOffsetModifierComponent.generated.h"

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class UFixedTargetOffsetModifierComponent : public UCameraModifierComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    FVector RelativeLocation;

    UPROPERTY(EditAnywhere)
    FRotator RelativeRotation;

    UFixedTargetOffsetModifierComponent();
};
