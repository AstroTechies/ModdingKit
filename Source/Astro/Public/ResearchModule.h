#pragma once
#include "CoreMinimal.h"
#include "PhysicalItem.h"
#include "ResearchModule.generated.h"

class UActorResearchComponent;
class UPowerComponent;
class UAdaptiveTickComponent;

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API AResearchModule : public APhysicalItem
{
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, Export, SaveGame, VisibleAnywhere, meta = (AllowPrivateAccess = true))
    UActorResearchComponent *ActorResearchComponent;

    UPROPERTY(BlueprintReadWrite, Export, SaveGame, VisibleAnywhere, meta = (AllowPrivateAccess = true))
    UPowerComponent *PowerComponent;

    UPROPERTY(BlueprintReadWrite, Export, VisibleAnywhere, meta = (AllowPrivateAccess = true))
    UAdaptiveTickComponent *AdaptiveTickComponent;

public:
    AResearchModule();
};
