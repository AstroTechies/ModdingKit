#pragma once
#include "CoreMinimal.h"
#include "DeformationParamsT2.h"
#include "SlotBehavior.h"
#include "SlotBehaviorTerrain.generated.h"

class APhysicalItem;

UCLASS(Blueprintable, EditInlineNew)
class USlotBehaviorTerrain : public USlotBehavior {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool AllowBodies;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HoverHeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool PlaceUpright;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bDisableCollisionAfterPlace: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bHighlightChildrenOfTarget: 1;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    APhysicalItem* Parent;
    
public:
    USlotBehaviorTerrain();

private:
    UFUNCTION(BlueprintCallable)
    void OnParentDeformed(const FDeformationParamsT2& params);
    
};

