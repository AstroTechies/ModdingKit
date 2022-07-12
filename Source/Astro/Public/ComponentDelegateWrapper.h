#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=HitResult -FallbackName=HitResult
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
//CROSS-MODULE INCLUDE V2: -ModuleName=InputCore -ObjectName=Key -FallbackName=Key
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
#include "ComponentDelegateWrapper.generated.h"

class AActor;
class UPrimitiveComponent;

UCLASS(Blueprintable)
class ASTRO_API UComponentDelegateWrapper : public UObject {
    GENERATED_BODY()
public:
    UComponentDelegateWrapper();
    UFUNCTION()
    void OnComponentHit(UPrimitiveComponent* ThisComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
    
    UFUNCTION()
    void OnActorClick(AActor* Actor, FKey Key);
    
};

