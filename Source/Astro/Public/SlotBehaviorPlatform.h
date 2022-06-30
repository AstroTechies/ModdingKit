#pragma once
#include "CoreMinimal.h"
#include "DeformationParamsT2.h"
#include "SlotBehavior.h"
#include "SlotBehaviorPlatform.generated.h"

class AActor;
class USceneComponent;
class APhysicalItem;
class UPrimitiveComponent;

UCLASS(Blueprintable, EditInlineNew)
class USlotBehaviorPlatform : public USlotBehavior
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool AllowBodies;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float HoverHeight;

    UPROPERTY(EditAnywhere)
    float KinematicMovementDuration;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TArray<FName> AnchorSampleComponents;

    UPROPERTY(EditAnywhere)
    uint8 bDisableCollisionAfterPlace : 1;

private:
    UPROPERTY()
    APhysicalItem *Parent;

    UPROPERTY(Export)
    TArray<USceneComponent *> AnchorComponents;

public:
    USlotBehaviorPlatform();

private:
    UFUNCTION()
    void OnParentDeformed(const FDeformationParamsT2 &params);

protected:
    UFUNCTION()
    void OnActorOverlappedDuringKinematicMovement(UPrimitiveComponent *ownerRootPrimitive, AActor *OverlappedActor, UPrimitiveComponent *OverlappedComponent);
};
