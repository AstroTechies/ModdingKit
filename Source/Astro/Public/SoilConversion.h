#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "SoilConversion.generated.h"

class UItemType;

USTRUCT(BlueprintType)
struct FSoilConversion {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemType> OutputItemType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 OutputRatio;
    
    ASTRO_API FSoilConversion();
};

