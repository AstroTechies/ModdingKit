#pragma once
#include "CoreMinimal.h"
#include "TerrainModifierBase.h"
#include "TerrainModifierLocal.generated.h"

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class ASTRO_API UTerrainModifierLocal : public UTerrainModifierBase
{
    GENERATED_BODY()
public:
    UTerrainModifierLocal();
};
