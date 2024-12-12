#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
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

