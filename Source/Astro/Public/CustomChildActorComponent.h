#pragma once
#include "CoreMinimal.h"
#include "Components/ChildActorComponent.h"
#include "CustomChildActorComponent.generated.h"

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class ASTRO_API UCustomChildActorComponent : public UChildActorComponent
{
    GENERATED_BODY()
public:
    UCustomChildActorComponent();
};
