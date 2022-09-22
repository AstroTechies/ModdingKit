#pragma once
#include "CoreMinimal.h"
#include "SlotBehavior.h"
#include "DeformationParamsT2.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Terrain2 -ObjectName=DeformationParamsT2 -FallbackName=DeformationParamsT2
#include "SlotBehaviorPlatform.generated.h"

class APhysicalItem;
class USceneComponent;
class AActor;
class UPrimitiveComponent;

UCLASS(Blueprintable, EditInlineNew)
class USlotBehaviorPlatform : public USlotBehavior {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool AllowBodies;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HoverHeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float KinematicMovementDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> AnchorSampleComponents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bDisableCollisionAfterPlace: 1;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    APhysicalItem* Parent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TArray<USceneComponent*> AnchorComponents;
    
public:
    USlotBehaviorPlatform();
private:
    UFUNCTION()
    void OnParentDeformed(const FDeformationParamsT2& params);
    
protected:
    UFUNCTION()
    void OnActorOverlappedDuringKinematicMovement(UPrimitiveComponent* ownerRootPrimitive, AActor* OverlappedActor, UPrimitiveComponent* OverlappedComponent);
    
};

