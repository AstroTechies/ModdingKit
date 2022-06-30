#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "Components/ActorComponent.h"
#include "RewardSelectionParameters.h"
#include "RewardResult.h"
#include "RewardComponent.generated.h"

class URewardSelectionTemplate;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class URewardComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    TSubclassOf<URewardSelectionTemplate> SelectionTemplate;

    UPROPERTY(EditAnywhere)
    FRewardSelectionParameters CustomSelectionParameters;

    UPROPERTY(EditAnywhere)
    uint8 bAllowMultipleUnlocks : 1;

    URewardComponent();
    UFUNCTION(BlueprintCallable)
    FRewardResult SelectReward();
};
