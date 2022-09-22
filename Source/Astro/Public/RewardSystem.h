#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
#include "RewardSelectionParameters.h"
#include "RewardResult.h"
#include "RewardSystem.generated.h"

class URewardTable;
class URewardState;
class AActor;
class UItemType;

UCLASS(Blueprintable)
class URewardSystem : public UObject {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    URewardState* RewardState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    URewardTable* RewardTable;
    
public:
    URewardSystem();
    UFUNCTION(BlueprintCallable)
    FRewardResult SelectReward(const FRewardSelectionParameters& params);
    
    UFUNCTION(BlueprintCallable)
    bool MarkActorTypeAsResearched(TSubclassOf<AActor> actorType);
    
    UFUNCTION(BlueprintPure)
    bool HasActorTypeBeenResearched(TSubclassOf<AActor> actorType) const;
    
    UFUNCTION(BlueprintCallable)
    bool GrantDurable(TSubclassOf<UItemType> itemToUnlock);
    
};

