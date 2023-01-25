#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PowerSlotComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UPowerSlotComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPowerSlotComponent();
};

