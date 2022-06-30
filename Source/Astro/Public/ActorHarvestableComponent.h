#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HarvestableItemSpawnerDefinition.h"
#include "Curves/CurveFloat.h"
#include "ActorHarvestableComponent.generated.h"

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class ASTRO_API UActorHarvestableComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    TArray<FHarvestableItemSpawnerDefinition> PrimaryItemSpawners;

    UPROPERTY(EditAnywhere)
    FRuntimeFloatCurve PrimaryItemNumberProbabilityCurve;

    UPROPERTY(EditAnywhere)
    TArray<FHarvestableItemSpawnerDefinition> SecondaryItemSpawners;

    UPROPERTY(EditAnywhere)
    FRuntimeFloatCurve SecondaryItemNumberWithPrimaryItemsProbabilityCurve;

    UPROPERTY(EditAnywhere)
    FRuntimeFloatCurve SecondaryItemNumberNoPrimaryItemsProbabilityCurve;

    UActorHarvestableComponent();
};
