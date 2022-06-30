#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ClickableParentProxy.generated.h"

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class ASTRO_API UClickableParentProxy : public UActorComponent
{
    GENERATED_BODY()
public:
    UClickableParentProxy();
};
