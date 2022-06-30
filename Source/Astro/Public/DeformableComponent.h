#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DeformableInterfaceT2.h"
#include "OnDeformedDelegate.h"
#include "DeformableComponent.generated.h"

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class ASTRO_API UDeformableComponent : public UActorComponent, public IDeformableInterfaceT2
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable)
    FOnDeformed OnDeformed;

    UDeformableComponent();

    // Fix for true pure virtual functions not being implemented
};
