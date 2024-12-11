#pragma once
#include "CoreMinimal.h"
#include "NamedEntityComponentDefinition.h"
#include "Templates/SubclassOf.h"
#include "AstroEntityDefinition.generated.h"

class UAstroEntitySystem;

USTRUCT(BlueprintType)
struct FAstroEntityDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bAllowViewRelevanceActorCreation: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UAstroEntitySystem>> SystemsDeterminingStatelessness;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FNamedEntityComponentDefinition> Components;
    
    ASTRO_API FAstroEntityDefinition();
};

