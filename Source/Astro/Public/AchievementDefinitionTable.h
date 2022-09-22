#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=DataAsset -FallbackName=DataAsset
#include "CountAchievement.h"
#include "FloatCountAchievement.h"
#include "ItemCollectionAchievement.h"
#include "ThresholdAchievementDefinition.h"
#include "AchievementDefinitionTable.generated.h"

UCLASS(Blueprintable)
class ASTRO_API UAchievementDefinitionTable : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FCountAchievement> CountAchievements;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FFloatCountAchievement> FloatCountAchievements;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FItemCollectionAchievement> ItemCollectionAchievements;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FThresholdAchievementDefinition> ThresholdAchievements;
    
    UAchievementDefinitionTable();
};

