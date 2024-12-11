#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EStatusModifierType.h"
#include "StatusModifierListenerComponent.generated.h"

class APlayerController;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UStatusModifierListenerComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UStatusModifierListenerComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnStatusModifierChanged(APlayerController* PlayerController, EStatusModifierType statusModifierType, float newValue);
    
};

