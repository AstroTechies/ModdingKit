#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DeformableInterfaceT2.h"
#include "OnDeformedDelegate.h"
#include "DeformableComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UDeformableComponent : public UActorComponent, public IDeformableInterfaceT2 {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnDeformed OnDeformed;
    
    UDeformableComponent(const FObjectInitializer& ObjectInitializer);


    // Fix for true pure virtual functions not being implemented
};

