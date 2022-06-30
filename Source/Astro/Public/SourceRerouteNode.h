#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SourceRerouteNode.generated.h"

USTRUCT(BlueprintType)
struct FSourceRerouteNode {
    GENERATED_BODY()
public:
    UPROPERTY()
    int32 NodeIndex;
    
    UPROPERTY()
    FVector FallbackNodeLocation;
    
    ASTRO_API FSourceRerouteNode();
};

