#pragma once
#include "CoreMinimal.h"
#include "DeformationParamsT2.h"
#include "SlotBehavior.h"
#include "SlotBehaviorPlatform.generated.h"

class AActor;
class APhysicalItem;
class UPrimitiveComponent;
class USceneComponent;

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
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<USceneComponent*> AnchorComponents;
    
public:
    USlotBehaviorPlatform();

private:
    UFUNCTION(BlueprintCallable)
    void OnParentDeformed(const FDeformationParamsT2& params);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnActorOverlappedDuringKinematicMovement(UPrimitiveComponent* ownerRootPrimitive, AActor* OverlappedActor, UPrimitiveComponent* OverlappedComponent);
    
};

