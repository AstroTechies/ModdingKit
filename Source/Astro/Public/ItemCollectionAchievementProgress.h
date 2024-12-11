#pragma once
#include "CoreMinimal.h"
#include "ItemCollectionAchievementProgress.generated.h"

USTRUCT(BlueprintType)
struct FItemCollectionAchievementProgress {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FName> CollectedItems;
    
    ASTRO_API FItemCollectionAchievementProgress();
};

