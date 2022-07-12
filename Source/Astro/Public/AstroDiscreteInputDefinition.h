#pragma once
#include "CoreMinimal.h"
#include "EAstroInputBindingNameMappings.h"
#include "AstroDiscreteInputDefinition.generated.h"

USTRUCT(BlueprintType)
struct FAstroDiscreteInputDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText DisplayName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAstroInputBindingNameMappings InputNameMapping;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AxisScale;
    
    ASTRO_API FAstroDiscreteInputDefinition();
};

