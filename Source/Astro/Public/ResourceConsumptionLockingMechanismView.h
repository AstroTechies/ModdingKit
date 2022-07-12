#pragma once
#include "CoreMinimal.h"
#include "LockingMechanismView.h"
#include "LockingMechanismSignalDelegate.h"
#include "LockChangedEventMetadata.h"
#include "ResourceConsumptionLockingMechanismView.generated.h"

class ULockingMechanism;

UCLASS(Blueprintable)
class ASTRO_API UResourceConsumptionLockingMechanismView : public ULockingMechanismView {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLockingMechanismSignal BeginFinalResourceConsumption;
    
    UResourceConsumptionLockingMechanismView();
    UFUNCTION()
    void OnBeginFinalResourceConsumption(ULockingMechanism* LockingMechanism, const FLockChangedEventMetadata& EventData);
    
};

