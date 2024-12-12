#pragma once
#include "CoreMinimal.h"
#include "EAstroColor.h"
#include "PlayerToastData.generated.h"

class UObject;

USTRUCT(BlueprintType)
struct FPlayerToastData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Title;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UObject* ResourceObjectBadge;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAstroColor BadgeColor;
    
    ASTRO_API FPlayerToastData();
};

