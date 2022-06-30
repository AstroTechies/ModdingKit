#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "CreativeModeTerrainData.h"
#include "UObject/NoExportTypes.h"
#include "CreativeModeData.generated.h"

class ULodAnchorComponent;

UCLASS(Blueprintable, BlueprintType)
class UCreativeModeData : public UObject
{
    GENERATED_BODY()
public:
    UPROPERTY()
    FCreativeModeTerrainData TerrainData;

    UPROPERTY(Export)
    TArray<ULodAnchorComponent *> LodAnchorComponents;

    UPROPERTY()
    FVector PlayerRefPos;

    UCreativeModeData();
    UFUNCTION(BlueprintCallable)
    FString GetTerrainPaintStatus();
};
