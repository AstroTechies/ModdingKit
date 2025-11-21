#pragma once
#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "BoxRemapComponent.generated.h"

class UChildActorComponent;

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UBoxRemapComponent : public UBoxComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UChildActorComponent* RemappedActor;
    
public:
    UBoxRemapComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SetRemappedActor(UChildActorComponent* remappedActorComponent);
    
};

