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
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAstroEntityComponentContainer> ComponentType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName LinkedActorComponentName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TArray<UAstroEntityComponentSubobjectDefinition*> ComponentSubobjectDefinitions;
    
    ASTRO_API FNamedEntityComponentDefinition();
};

