#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AstroSaveAsset.generated.h"

class UWorld;

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API UAstroSaveAsset : public UObject
{
    GENERATED_BODY()
public:
    UPROPERTY(VisibleDefaultsOnly)
    TSoftObjectPtr<UWorld> SaveLevel;

    UPROPERTY()
    TArray<uint8> SaveData;

    UAstroSaveAsset();
};
