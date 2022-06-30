#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "NamedEntityComponentDefinition.generated.h"

class UAstroEntityComponentContainer;
class UAstroEntityComponentSubobjectDefinition;

USTRUCT(BlueprintType)
struct FNamedEntityComponentDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(EditDefaultsOnly)
    FName Name;
    
    UPROPERTY(EditDefaultsOnly)
    TSubclassOf<UAstroEntityComponentContainer> ComponentType;
    
    UPROPERTY(EditDefaultsOnly)
    FName LinkedActorComponentName;
    
    UPROPERTY(EditDefaultsOnly, Export)
    TArray<UAstroEntityComponentSubobjectDefinition*> ComponentSubobjectDefinitions;
    
    ASTRO_API FNamedEntityComponentDefinition();
};

