#pragma once
#include "CoreMinimal.h"
#include "OneTimeTooltipList.h"
#include "Templates/SubclassOf.h"
#include "AstroPlayerIdOneTimeTooltipStatePair.generated.h"

class UItemType;

USTRUCT(BlueprintType)
struct FAstroPlayerIdOneTimeTooltipStatePair {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FString PlayerId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FOneTimeTooltipList> TriggeredOneTimeItemTooltips;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, NotReplicated, Transient, meta=(AllowPrivateAccess=true))
    TMap<TSubclassOf<UItemType>, FOneTimeTooltipList> OneTimeItemTooltipsMap;
    
    ASTRO_API FAstroPlayerIdOneTimeTooltipStatePair();
};

