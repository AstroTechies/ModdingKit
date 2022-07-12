#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=DataAsset -FallbackName=DataAsset
#include "SoilConversion.h"
#include "SoilConversionTable.generated.h"

UCLASS(Blueprintable)
class ASTRO_API USoilConversionTable : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSoilConversion> SoilConversions;
    
    USoilConversionTable();
};

