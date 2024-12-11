#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CacheResourceGroup.h"
#include "Templates/SubclassOf.h"
#include "ExtractorGroupResourceCache.generated.h"

class AAstroPlanet;
class UItemType;

USTRUCT(BlueprintType)
struct FExtractorGroupResourceCache {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AAstroPlanet> Planet;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FVector> ResourcePositions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<uint8> CollectionProgress;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FCacheResourceGroup> Groups;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UItemType>> ContainedItemTypes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<int32> MemberStatesIndices;
    
    ASTRO_API FExtractorGroupResourceCache();
};

