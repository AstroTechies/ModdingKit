#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "InputCoreTypes.h"
#include "ComponentDelegateWrapper.generated.h"

class UPrimitiveComponent;
class AActor;

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API UComponentDelegateWrapper : public UObject
{
    GENERATED_BODY()
public:
    UComponentDelegateWrapper();
    UFUNCTION()
    void OnComponentHit(UPrimitiveComponent *ThisComp, AActor *OtherActor, UPrimitiveComponent *OtherComp, FVector NormalImpulse, const FHitResult &Hit);

    UFUNCTION()
    void OnActorClick(AActor *Actor, FKey Key);
};
