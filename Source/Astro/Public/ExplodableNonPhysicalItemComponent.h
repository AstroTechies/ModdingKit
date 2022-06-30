#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ExplodableNonPhysicalItemComponent.generated.h"

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class ASTRO_API UExplodableNonPhysicalItemComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(EditDefaultsOnly)
    int32 ToolMoveTier;

    UExplodableNonPhysicalItemComponent();
};
