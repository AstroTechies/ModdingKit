#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Templates/SubclassOf.h"
#include "ResourceSinkValues.generated.h"

class UItemType;

UCLASS(Blueprintable)
class UResourceSinkValues : public UDataAsset {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TSubclassOf<UItemType>, int32> ScoreByResourceItemType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TSubclassOf<UItemType>, int32> ScoreBySeedItemType;
    
public:
    UResourceSinkValues();

    UFUNCTION(BlueprintCallable)
    int32 GetScoreBySeedItemType(const TSubclassOf<UItemType>& ItemType);
    
    UFUNCTION(BlueprintCallable)
    int32 GetScoreByResourceItemType(const TSubclassOf<UItemType>& ItemType);
    
};

