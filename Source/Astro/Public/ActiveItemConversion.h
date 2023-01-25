#pragma once
#include "CoreMinimal.h"
#include "ActiveItemConversionItemInput.h"
#include "ActiveItemConversionItemOutput.h"
#include "AstroDatumRef.h"
#include "ActiveItemConversion.generated.h"

USTRUCT(BlueprintType)
struct FActiveItemConversion {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FAstroDatumRef> InputItemEntityRefs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FActiveItemConversionItemInput> ItemInputs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FActiveItemConversionItemOutput> ItemOutputs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float ProgressRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 ID;
    
    ASTRO_API FActiveItemConversion();
};

