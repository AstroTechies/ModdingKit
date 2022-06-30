#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "SoilConversion.h"
#include "SoilConversionTable.generated.h"

UCLASS(Blueprintable, BlueprintType)
class ASTRO_API USoilConversionTable : public UDataAsset
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    TArray<FSoilConversion> SoilConversions;

    USoilConversionTable();
};
