#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SourceRerouteNode.generated.h"

USTRUCT(BlueprintType)
struct FSourceRerouteNode {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 NodeIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector FallbackNodeLocation;
    
    ASTRO_API FSourceRerouteNode();
};

