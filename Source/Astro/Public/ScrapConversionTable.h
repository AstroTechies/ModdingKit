#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Templates/SubclassOf.h"
#include "ScrapConversionTable.generated.h"

class UItemType;

UCLASS(Blueprintable)
class ASTRO_API UScrapConversionTable : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TSubclassOf<UItemType>, float> ScrapConversionTable;
    
    UScrapConversionTable();

};

