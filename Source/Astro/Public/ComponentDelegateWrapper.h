#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "InputCoreTypes.h"
#include "ComponentDelegateWrapper.generated.h"

class AActor;
class UPrimitiveComponent;

UCLASS(Blueprintable)
class ASTRO_API UComponentDelegateWrapper : public UObject {
    GENERATED_BODY()
public:
    UComponentDelegateWrapper();

    UFUNCTION(BlueprintCallable)
    void OnComponentHit(UPrimitiveComponent* ThisComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
    
    UFUNCTION(BlueprintCallable)
    void OnActorClick(AActor* Actor, FKey Key);
    
};

