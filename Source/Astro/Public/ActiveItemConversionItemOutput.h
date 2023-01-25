#pragma once
#include "CoreMinimal.h"
#include "AstroDatumRef.h"
#include "Templates/SubclassOf.h"
#include "ActiveItemConversionItemOutput.generated.h"

class UItemType;

USTRUCT(BlueprintType)
struct FActiveItemConversionItemOutput {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemType> OutputItemType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 TargetOutputItemAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 OutputItemAmountProduced;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FAstroDatumRef CurrentOutputItemEntityRef;
    
    ASTRO_API FActiveItemConversionItemOutput();
};

