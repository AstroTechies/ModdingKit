#pragma once
#include "CoreMinimal.h"
#include "EPlanetIdentifier.h"
#include "FirewallState.h"
#include "PlanetFirewallStates.generated.h"

USTRUCT(BlueprintType)
struct FPlanetFirewallStates {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    EPlanetIdentifier planetID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FFirewallState> FirewallStates;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 HackedGatewayCompleteCount;
    
    ASTRO_API FPlanetFirewallStates();
};

