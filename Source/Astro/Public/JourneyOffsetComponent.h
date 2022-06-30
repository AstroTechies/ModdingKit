#pragma once
#include "CoreMinimal.h"
#include "CameraModifierComponent.h"
#include "JourneyOffsetComponent.generated.h"

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class ASTRO_API UJourneyOffsetComponent : public UCameraModifierComponent
{
    GENERATED_BODY()
public:
private:
    UPROPERTY(EditAnywhere)
    float OffsetAmount;

public:
    UJourneyOffsetComponent();
};
