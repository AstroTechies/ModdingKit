#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PowerSlotComponent.generated.h"

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class ASTRO_API UPowerSlotComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPowerSlotComponent();
};
