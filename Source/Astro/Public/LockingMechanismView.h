#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "LockChangedEventMetadata.h"
#include "SignalDelegate.h"
#include "LockingMechanismView.generated.h"

class ULockingMechanism;
class ULockingMechanismDefinition;

UCLASS(Blueprintable, BlueprintType)
class ASTRO_API ULockingMechanismView : public UObject
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable)
    FSignal OnOpenChanged;

    UPROPERTY(BlueprintReadWrite, ReplicatedUsing = OnRep_IsOpen, meta = (AllowPrivateAccess = true))
    uint8 bIsOpen : 1;

    UPROPERTY(Transient)
    ULockingMechanism *LinkedLockingMechanism;

    UPROPERTY(BlueprintReadWrite, Transient, meta = (AllowPrivateAccess = true))
    ULockingMechanismDefinition *Definition;

    ULockingMechanismView();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

    UFUNCTION()
    void OnRep_IsOpen();

    UFUNCTION()
    void OnOpenStateChanged(ULockingMechanism *LockingMechanism, const FLockChangedEventMetadata &EventData);
};
