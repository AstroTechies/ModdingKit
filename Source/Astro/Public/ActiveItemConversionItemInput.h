#pragma once
#include "CoreMinimal.h"
#include "AstroDatumRef.h"
#include "Templates/SubclassOf.h"
#include "ActiveItemConversionItemInput.generated.h"

class UItemType;

USTRUCT(BlueprintType)
struct FActiveItemConversionItemInput {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemType> InputItemType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FAstroDatumRef InputItemEntityRef;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 StartingInputItemAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 TargetInputItemAmount;
    
    ASTRO_API FActiveItemConversionItemInput();
};

