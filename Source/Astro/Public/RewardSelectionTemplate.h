#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
#include "RewardSelectionParameters.h"
#include "RewardSelectionTemplate.generated.h"

UCLASS(Blueprintable)
class URewardSelectionTemplate : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRewardSelectionParameters SelectionParameters;
    
    URewardSelectionTemplate();
};

