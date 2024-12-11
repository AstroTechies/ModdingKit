#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "RewardSublist.h"
#include "Templates/SubclassOf.h"
#include "RewardState.generated.h"

class AActor;
class UItemType;

UCLASS(Blueprintable)
class URewardState : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UItemType>> UnlockedDurables;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<AActor>> ResearchedTypes;
    
    UPROPERTY(EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TMap<uint64, FRewardSublist> RewardSublists;
    
    URewardState();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsUnlocked(TSubclassOf<UItemType> ItemType) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsKnown(TSubclassOf<UItemType> ItemType) const;
    
};

