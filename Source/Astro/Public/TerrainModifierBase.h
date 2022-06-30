#pragma once
#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "TerrainModifierBase.generated.h"

UCLASS(Blueprintable, Abstract, meta = (BlueprintSpawnableComponent))
class ASTRO_API UTerrainModifierBase : public USceneComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    bool Enabled;

    UPROPERTY(EditAnywhere)
    int32 SeedOffset;

    UPROPERTY(EditAnywhere)
    int32 EvaluationDepth;

    UPROPERTY(EditAnywhere)
    int32 EdgeEvaluationDepth;

    UTerrainModifierBase();
};
