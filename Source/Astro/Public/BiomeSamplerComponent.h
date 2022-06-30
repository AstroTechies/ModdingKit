#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "OnBiomeSampleUpdatedDelegate.h"
#include "BiomeSamplerComponent.generated.h"

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class ASTRO_API UBiomeSamplerComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    float TickFrequency;

    UPROPERTY()
    FOnBiomeSampleUpdated OnBiomeSampleUpdated;

    UBiomeSamplerComponent();
};
