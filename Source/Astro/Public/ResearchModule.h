#pragma once
#include "CoreMinimal.h"
#include "PhysicalItem.h"
#include "ResearchModule.generated.h"

class UPowerComponent;
class UActorResearchComponent;
class UAdaptiveTickComponent;

UCLASS(Blueprintable)
class ASTRO_API AResearchModule : public APhysicalItem {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, SaveGame, meta=(AllowPrivateAccess=true))
    UActorResearchComponent* ActorResearchComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, SaveGame, meta=(AllowPrivateAccess=true))
    UPowerComponent* PowerComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UAdaptiveTickComponent* AdaptiveTickComponent;
    
public:
    AResearchModule();
};

