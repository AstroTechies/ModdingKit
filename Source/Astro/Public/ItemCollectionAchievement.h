#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "ProgressionAchievementDefinition.h"
#include "ItemCollectionAchievement.generated.h"

class UItemList;

USTRUCT(BlueprintType)
struct FItemCollectionAchievement : public FProgressionAchievementDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemList> CollectionItems;
    
    ASTRO_API FItemCollectionAchievement();
};

