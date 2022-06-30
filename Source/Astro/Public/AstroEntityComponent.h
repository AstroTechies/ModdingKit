#pragma once
#include "CoreMinimal.h"
#include "AstroDatum.h"
#include "AstroEntityComponent.generated.h"

class UActorComponent;
class UAstroEntityComponentSubobject;

USTRUCT(BlueprintType)
struct FAstroEntityComponent : public FAstroDatum {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, SaveGame, meta=(AllowPrivateAccess=true))
    FName Name;
    
    UPROPERTY(BlueprintReadWrite, SaveGame, meta=(AllowPrivateAccess=true))
    FName ViewActorComponentName;
    
    UPROPERTY(BlueprintReadWrite, Export, SaveGame, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UActorComponent> ViewActorComponent;
    
    UPROPERTY(BlueprintReadWrite, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UActorComponent> ViewActorTemplateComponent;
    
    UPROPERTY(SaveGame)
    TArray<UAstroEntityComponentSubobject*> OwnedSubobjects;
    
    ASTRO_API FAstroEntityComponent();
};

