#pragma once
#include "CoreMinimal.h"
#include "AstroWidgetContentDataTabBarEntry.generated.h"

class UObject;

USTRUCT(BlueprintType)
struct FAstroWidgetContentDataTabBarEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UObject* ResourceObject;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UObject* ResourceObjectBG;
    
    ASTRO_API FAstroWidgetContentDataTabBarEntry();
};

