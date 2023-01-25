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
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FName ViewActorComponentName;
    
    UPROPERTY(EditAnywhere, Export, SaveGame, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UActorComponent> ViewActorComponent;
    
    UPROPERTY(EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UActorComponent> ViewActorTemplateComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<UAstroEntityComponentSubobject*> OwnedSubobjects;
    
    ASTRO_API FAstroEntityComponent();
};

