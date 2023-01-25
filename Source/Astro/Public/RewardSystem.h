#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
#include "RewardResult.h"
#include "RewardSelectionParameters.h"
#include "Templates/SubclassOf.h"
#include "RewardSystem.generated.h"

class AActor;
class UItemType;
class URewardState;
class URewardTable;

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
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasActorTypeBeenResearched(TSubclassOf<AActor> actorType) const;
    
    UFUNCTION(BlueprintCallable)
    bool GrantDurable(TSubclassOf<UItemType> itemToUnlock);
    
};

