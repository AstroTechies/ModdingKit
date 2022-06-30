#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "UObject/Object.h"
#include "RewardResult.h"
#include "RewardSelectionParameters.h"
#include "RewardSystem.generated.h"

class AActor;
class URewardState;
class URewardTable;
class UItemType;

UCLASS(Blueprintable, BlueprintType)
class URewardSystem : public UObject
{
    GENERATED_BODY()
public:
private:
    UPROPERTY(Transient)
    URewardState *RewardState;

    UPROPERTY(Transient)
    URewardTable *RewardTable;

public:
    URewardSystem();
    UFUNCTION(BlueprintCallable)
    FRewardResult SelectReward(const FRewardSelectionParameters &params);

    UFUNCTION(BlueprintCallable)
    bool MarkActorTypeAsResearched(TSubclassOf<AActor> actorType);

    UFUNCTION(BlueprintPure)
    bool HasActorTypeBeenResearched(TSubclassOf<AActor> actorType) const;

    UFUNCTION(BlueprintCallable)
    bool GrantDurable(TSubclassOf<UItemType> itemToUnlock);
};
