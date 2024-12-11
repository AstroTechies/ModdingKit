#pragma once
#include "CoreMinimal.h"
#include "TerrainModifierBase.h"
#include "TerrainModifierLocal.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UTerrainModifierLocal : public UTerrainModifierBase {
    GENERATED_BODY()
public:
    UTerrainModifierLocal(const FObjectInitializer& ObjectInitializer);

};

