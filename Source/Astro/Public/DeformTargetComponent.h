#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Transform -FallbackName=Transform
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
#include "Components/ActorComponent.h"
#include "DeformTargetSignalDelegate.h"
#include "SlotReference.h"
#include "DeformTargetComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UDeformTargetComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSlotReference> TargetSlots;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDeformTargetSignal OnDeform;
    
    UDeformTargetComponent();
    UFUNCTION(BlueprintCallable)
    FTransform GetDeformTarget(const FVector& sourceLocation);
    
};

