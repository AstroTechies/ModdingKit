#pragma once
#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "AstroAssetManager.generated.h"

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API UAstroAssetManager : public UAssetManager
{
    GENERATED_BODY()
public:
    UAstroAssetManager();
};
