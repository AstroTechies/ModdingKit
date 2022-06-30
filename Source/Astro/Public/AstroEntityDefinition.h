#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "NamedEntityComponentDefinition.h"
#include "AstroEntityDefinition.generated.h"

class UAstroEntitySystem;

USTRUCT(BlueprintType)
struct FAstroEntityDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(EditDefaultsOnly)
    uint8 bAllowViewRelevanceActorCreation: 1;
    
    UPROPERTY(EditDefaultsOnly)
    TArray<TSubclassOf<UAstroEntitySystem>> SystemsDeterminingStatelessness;
    
    UPROPERTY(EditDefaultsOnly)
    TArray<FNamedEntityComponentDefinition> Components;
    
    ASTRO_API FAstroEntityDefinition();
};

