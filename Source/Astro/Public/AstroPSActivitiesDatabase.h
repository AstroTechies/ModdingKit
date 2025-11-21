#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "AstroActivityChain.h"
#include "AstroActivityData.h"
#include "EAstroPSActivity.h"
#include "AstroPSActivitiesDatabase.generated.h"

UCLASS(Blueprintable)
class UAstroPSActivitiesDatabase : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EAstroPSActivity, FAstroActivityData> PSActivityData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EAstroPSActivity, FAstroActivityChain> PSActivityMissionChainData;
    
    UAstroPSActivitiesDatabase();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasCompletedMissionChain(const FName& CompletedMissionId, const TArray<FName>& CompletedMissionIds) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FName> GetMissionIdsForChainByMissionId(const FName& missionId) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FName> GetMissionIdsForChainByActivity(const EAstroPSActivity& Activity) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FName> GetAllActivityNames() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EAstroPSActivity GetActivityForMissionId(const FName& missionId) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetActivityAvalibility(const FName& ActivityName) const;
    
};

