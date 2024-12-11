#pragma once
#include "CoreMinimal.h"
#include "AstroCustomMultiToolSettings.generated.h"

USTRUCT(BlueprintType)
struct FAstroCustomMultiToolSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float ToolStrengthNormalized;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float ToolSizeNormalized;
    
    ASTRO_API FAstroCustomMultiToolSettings();
};

