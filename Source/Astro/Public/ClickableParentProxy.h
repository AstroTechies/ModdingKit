#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ClickableParentProxy.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UClickableParentProxy : public UActorComponent {
    GENERATED_BODY()
public:
    UClickableParentProxy(const FObjectInitializer& ObjectInitializer);

};

