#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Terrain2 -ObjectName=DeformableInterfaceT2 -FallbackName=DeformableInterfaceT2
#include "DeformableInterfaceT2.h"
#include "OnDeformedDelegate.h"
#include "DeformableComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UDeformableComponent : public UActorComponent, public IDeformableInterfaceT2 {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnDeformed OnDeformed;
    
    UDeformableComponent();
    
    // Fix for true pure virtual functions not being implemented
};

