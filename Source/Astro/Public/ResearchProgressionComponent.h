#pragma once
#include "CoreMinimal.h"
#include "AstroEntityComponent.h"
#include "CumulativeResearchTracker.h"
#include "OnCurrentResearchPointBalanceChangedDelegate.h"
#include "OnItemTypeListChangedDelegate.h"
#include "Templates/SubclassOf.h"
#include "ResearchProgressionComponent.generated.h"

class UItemType;

USTRUCT(BlueprintType)
struct FResearchProgressionComponent : public FAstroEntityComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UItemType>> KnownItemTypes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UItemType>> UnlockedItemTypes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FName> CompletedBonusTimelines;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FCumulativeResearchTracker TotalResearch;
    
private:
    UPROPERTY(EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    double CurrentPointBalance;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CurrentDisplayedPointBalance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CurrentResearchPointsPerMinute;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnCurrentResearchPointBalanceChanged OnCurrentPointBalanceChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnItemTypeListChanged OnKnownItemsChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnItemTypeListChanged OnUnlockedItemsChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TMap<FName, FCumulativeResearchTracker> ActiveBonusTimelineProgress;
    
    ASTRO_API FResearchProgressionComponent();
};

