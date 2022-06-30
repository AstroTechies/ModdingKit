#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "Engine/DataAsset.h"
#include "ScrapConversionTable.generated.h"

class UItemType;

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API UScrapConversionTable : public UDataAsset
{
    GENERATED_BODY()
public:
    UPROPERTY(EditDefaultsOnly)
    TMap<TSubclassOf<UItemType>, float> ScrapConversionTable;

    UScrapConversionTable();
};
