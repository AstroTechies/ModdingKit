#pragma once
#include "CoreMinimal.h"
#include "CountAchievement.h"
#include "Engine/DataAsset.h"
#include "FloatCountAchievement.h"
#include "ItemCollectionAchievement.h"
#include "ThresholdAchievementDefinition.h"
#include "AchievementDefinitionTable.generated.h"

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API UAchievementDefinitionTable : public UDataAsset
{
    GENERATED_BODY()
public:
    UPROPERTY(EditDefaultsOnly)
    TArray<FCountAchievement> CountAchievements;

    UPROPERTY(EditDefaultsOnly)
    TArray<FFloatCountAchievement> FloatCountAchievements;

    UPROPERTY(EditDefaultsOnly)
    TArray<FItemCollectionAchievement> ItemCollectionAchievements;

    UPROPERTY(EditDefaultsOnly)
    TArray<FThresholdAchievementDefinition> ThresholdAchievements;

    UAchievementDefinitionTable();
};
