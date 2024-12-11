#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "CreativeModeTerrainData.h"
#include "CreativeModeData.generated.h"

class ULodAnchorComponent;

UCLASS(Blueprintable)
class UCreativeModeData : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCreativeModeTerrainData TerrainData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<ULodAnchorComponent*> LodAnchorComponents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector PlayerRefPos;
    
    UCreativeModeData();

    UFUNCTION(BlueprintCallable)
    FString GetTerrainPaintStatus();
    
};

