#pragma once
#include "CoreMinimal.h"
#include "SingleUseConsumableComponent.h"
#include "ActorResearchPointGrantComponent.generated.h"

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class ASTRO_API UActorResearchPointGrantComponent : public USingleUseConsumableComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(EditDefaultsOnly)
    float MinPointsGranted;

    UPROPERTY(EditDefaultsOnly)
    float MaxPointsGranted;

    UActorResearchPointGrantComponent();
};
