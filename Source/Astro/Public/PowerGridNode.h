#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PowerGridNode.generated.h"

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class UPowerGridNode : public UActorComponent
{
    GENERATED_BODY()
public:
    UPowerGridNode();
};
