#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "UObject/Object.h"
#include "RewardSublist.h"
#include "RewardState.generated.h"

class UItemType;
class AActor;

UCLASS(Blueprintable, BlueprintType)
class URewardState : public UObject
{
    GENERATED_BODY()
public:
    UPROPERTY(SaveGame)
    TArray<TSubclassOf<UItemType>> UnlockedDurables;

    UPROPERTY(SaveGame)
    TArray<TSubclassOf<AActor>> ResearchedTypes;

    UPROPERTY(SaveGame)
    TMap<uint64, FRewardSublist> RewardSublists;

    URewardState();
    UFUNCTION(BlueprintPure)
    bool IsUnlocked(TSubclassOf<UItemType> ItemType) const;
};
