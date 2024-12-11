#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PersistRootComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UPersistRootComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPersistRootComponent(const FObjectInitializer& ObjectInitializer);

};

