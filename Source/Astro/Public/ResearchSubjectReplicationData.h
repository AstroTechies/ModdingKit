#pragma once
#include "CoreMinimal.h"
#include "ResearchSubjectReplicationData.generated.h"

class UItemType;
class UResearchSubjectDefinition;

USTRUCT(BlueprintType)
struct FResearchSubjectReplicationData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UResearchSubjectDefinition> Definition;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UItemType> ItemType;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    float TimeProgressRatio;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    float PointsProgressRatio;
    
    ASTRO_API FResearchSubjectReplicationData();
};

