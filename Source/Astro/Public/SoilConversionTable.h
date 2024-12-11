#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
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

