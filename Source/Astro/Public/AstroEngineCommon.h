#pragma once
#include "CoreMinimal.h"
#include "AstroEngineCommon.generated.h"

class UAstroErrorWidget;

USTRUCT(BlueprintType)
struct ASTRO_API FAstroEngineCommon {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UAstroErrorWidget* ErrorWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UAstroErrorWidget* SessionOperationInProgressWidget;
    
public:
    FAstroEngineCommon();
};

