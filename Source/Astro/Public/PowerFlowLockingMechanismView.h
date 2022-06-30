#pragma once
#include "CoreMinimal.h"
#include "LockingMechanismView.h"
#include "LockChangedEventMetadata.h"
#include "SignalDelegate.h"
#include "PowerFlowLockingMechanismView.generated.h"

class ULockingMechanism;

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API UPowerFlowLockingMechanismView : public ULockingMechanismView
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable)
    FSignal OnCompletionRatioChanged;

    UPROPERTY(BlueprintReadWrite, ReplicatedUsing = OnRep_CompletionRatio, meta = (AllowPrivateAccess = true))
    float CompletionRatio;

    UPowerFlowLockingMechanismView();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

    UFUNCTION()
    void OnRep_CompletionRatio();

    UFUNCTION()
    void OnAccumulatedFullyPoweredTimeChanged(ULockingMechanism *LockingMechanism, const FLockChangedEventMetadata &EventData);
};
