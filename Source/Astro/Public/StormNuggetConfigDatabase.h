#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "StormNuggetConfigDatabase.generated.h"

class UItemType;

USTRUCT(BlueprintType)
struct FStormNuggetConfigDatabase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UItemType>> StormDataNuggets;
    
    ASTRO_API FStormNuggetConfigDatabase();
};

