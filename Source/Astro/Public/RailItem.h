#pragma once
#include "CoreMinimal.h"
#include "RailItem.generated.h"

class APhysicalItem;

USTRUCT(BlueprintType)
struct FRailItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    APhysicalItem* Item;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Alpha;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Direction;
    
    ASTRO_API FRailItem();
};

