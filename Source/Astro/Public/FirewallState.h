#pragma once
#include "CoreMinimal.h"
#include "FirewallState.generated.h"

class AActor;

USTRUCT(BlueprintType)
struct FFirewallState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    AActor* FirewallActor;
    
    ASTRO_API FFirewallState();
};

