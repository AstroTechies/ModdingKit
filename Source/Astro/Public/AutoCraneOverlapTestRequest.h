#pragma once
#include "CoreMinimal.h"
#include "AutoCraneOverlapTestRequest.generated.h"

class AAutoCrane;

USTRUCT(BlueprintType)
struct FAutoCraneOverlapTestRequest {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AAutoCrane* AutoCrane;
    
    ASTRO_API FAutoCraneOverlapTestRequest();
};

