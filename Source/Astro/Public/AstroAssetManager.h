#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=AssetManager -FallbackName=AssetManager
#include "Engine/AssetManager.h"
#include "AstroAssetManager.generated.h"

UCLASS(Blueprintable)
class ASTRO_API UAstroAssetManager : public UAssetManager {
    GENERATED_BODY()
public:
    UAstroAssetManager();
};

