#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
#include "RewardSublist.h"
#include "RewardState.generated.h"

class UItemType;
class AActor;

UCLASS(Blueprintable)
class URewardState : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UItemType>> UnlockedDurables;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<AActor>> ResearchedTypes;
    
    UPROPERTY(EditAnywhere, SaveGame)
    TMap<uint64, FRewardSublist> RewardSublists;
    
    URewardState();
    UFUNCTION(BlueprintPure)
    bool IsUnlocked(TSubclassOf<UItemType> ItemType) const;
    
};

