#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "AstroEntityComponent.h"
#include "CumulativeResearchTracker.h"
#include "OnItemTypeListChangedDelegate.h"
#include "OnCurrentResearchPointBalanceChangedDelegate.h"
#include "ResearchProgressionComponent.generated.h"

class UItemType;

USTRUCT(BlueprintType)
struct FResearchProgressionComponent : public FAstroEntityComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UItemType>> KnownItemTypes;
    
    UPROPERTY(BlueprintReadWrite, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UItemType>> UnlockedItemTypes;
    
    UPROPERTY(BlueprintReadWrite, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FName> CompletedBonusTimelines;
    
    UPROPERTY(BlueprintReadWrite, SaveGame, meta=(AllowPrivateAccess=true))
    FCumulativeResearchTracker TotalResearch;
    
private:
    UPROPERTY(SaveGame)
    double CurrentPointBalance;
    
public:
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    float CurrentDisplayedPointBalance;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    float CurrentResearchPointsPerMinute;
    
    UPROPERTY()
    FOnCurrentResearchPointBalanceChanged OnCurrentPointBalanceChanged;
    
    UPROPERTY()
    FOnItemTypeListChanged OnKnownItemsChanged;
    
    UPROPERTY()
    FOnItemTypeListChanged OnUnlockedItemsChanged;
    
    UPROPERTY(BlueprintReadWrite, SaveGame, meta=(AllowPrivateAccess=true))
    TMap<FName, FCumulativeResearchTracker> ActiveBonusTimelineProgress;
    
    ASTRO_API FResearchProgressionComponent();
};

