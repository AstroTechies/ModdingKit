#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
#include "CacheResourceGroup.h"
#include "ExtractorGroupResourceCache.generated.h"

class AAstroPlanet;
class UItemType;

USTRUCT(BlueprintType)
struct FExtractorGroupResourceCache {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, SaveGame)
    TWeakObjectPtr<AAstroPlanet> Planet;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FVector> ResourcePositions;
    
    UPROPERTY(EditAnywhere, SaveGame)
    TArray<uint8> CollectionProgress;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FCacheResourceGroup> Groups;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UItemType>> ContainedItemTypes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<int32> MemberStatesIndices;
    
    ASTRO_API FExtractorGroupResourceCache();
};

