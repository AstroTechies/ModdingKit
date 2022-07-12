#pragma once
#include "CoreMinimal.h"
#include "ResearchSubjectReplicationData.generated.h"

class UResearchSubjectDefinition;
class UItemType;

USTRUCT(BlueprintType)
struct FResearchSubjectReplicationData {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    TWeakObjectPtr<UResearchSubjectDefinition> Definition;
    
    UPROPERTY(EditAnywhere)
    TWeakObjectPtr<UItemType> ItemType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TimeProgressRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PointsProgressRatio;
    
    ASTRO_API FResearchSubjectReplicationData();
};

