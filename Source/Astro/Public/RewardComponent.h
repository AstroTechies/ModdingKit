#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RewardResult.h"
#include "RewardSelectionParameters.h"
#include "Templates/SubclassOf.h"
#include "RewardComponent.generated.h"

class URewardSelectionTemplate;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class URewardComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<URewardSelectionTemplate> SelectionTemplate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRewardSelectionParameters CustomSelectionParameters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bAllowMultipleUnlocks: 1;
    
    URewardComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    FRewardResult SelectReward();
    
};

