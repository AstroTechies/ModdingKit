#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "UObject/NoExportTypes.h"
#include "CacheResourceGroup.h"
#include "ExtractorGroupResourceCache.generated.h"

class AAstroPlanet;
class UItemType;

USTRUCT(BlueprintType)
struct FExtractorGroupResourceCache {
    GENERATED_BODY()
public:
    UPROPERTY(SaveGame)
    TWeakObjectPtr<AAstroPlanet> Planet;
    
    UPROPERTY(SaveGame)
    TArray<FVector> ResourcePositions;
    
    UPROPERTY(SaveGame)
    TArray<uint8> CollectionProgress;
    
    UPROPERTY(SaveGame)
    TArray<FCacheResourceGroup> Groups;
    
    UPROPERTY(SaveGame)
    TArray<TSubclassOf<UItemType>> ContainedItemTypes;
    
    UPROPERTY(SaveGame)
    TArray<int32> MemberStatesIndices;
    
    ASTRO_API FExtractorGroupResourceCache();
};

