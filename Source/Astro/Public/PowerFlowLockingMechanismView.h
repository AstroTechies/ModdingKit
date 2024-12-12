#pragma once
#include "CoreMinimal.h"
#include "LockChangedEventMetadata.h"
#include "LockingMechanismView.h"
#include "SignalDelegate.h"
#include "PowerFlowLockingMechanismView.generated.h"

class ULockingMechanism;

UCLASS(Blueprintable)
class ASTRO_API UPowerFlowLockingMechanismView : public ULockingMechanismView {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnCompletionRatioChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_CompletionRatio, meta=(AllowPrivateAccess=true))
    float CompletionRatio;
    
    UPowerFlowLockingMechanismView();

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    void OnRep_CompletionRatio();
    
    UFUNCTION(BlueprintCallable)
    void OnAccumulatedFullyPoweredTimeChanged(ULockingMechanism* LockingMechanism, const FLockChangedEventMetadata& EventData);
    
};

