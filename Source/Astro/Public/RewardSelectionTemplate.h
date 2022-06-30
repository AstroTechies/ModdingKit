#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "RewardSelectionParameters.h"
#include "RewardSelectionTemplate.generated.h"

UCLASS(Blueprintable, Blueprintable)
class URewardSelectionTemplate : public UObject
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    FRewardSelectionParameters SelectionParameters;

    URewardSelectionTemplate();
};
