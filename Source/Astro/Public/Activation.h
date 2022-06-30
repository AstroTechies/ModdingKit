#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "SignalDelegate.h"
#include "EnableSignalDelegate.h"
#include "SignalActivationBinding.h"
#include "Activation.generated.h"

class UActivation;

UCLASS(Blueprintable, BlueprintType)
class UActivation : public UObject
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable)
    FSignal OnActivate;

    UPROPERTY(BlueprintAssignable)
    FSignal OnDeactivate;

    UPROPERTY(BlueprintAssignable)
    FEnableSignal OnChange;

protected:
    UPROPERTY(Transient)
    bool m_bActive;

    UPROPERTY()
    TArray<FSignalActivationBinding> Bindings;

public:
    UActivation();
    UFUNCTION(BlueprintCallable)
    bool Update(bool Active);

    UFUNCTION(BlueprintCallable)
    void UnbindTo(UActivation *Other);

    UFUNCTION(BlueprintCallable)
    void Toggle();

    UFUNCTION(BlueprintPure)
    bool IsActive();

    UFUNCTION(BlueprintCallable)
    void Deactivate();

    UFUNCTION(BlueprintCallable)
    void BindTo(UActivation *Other);

    UFUNCTION(BlueprintCallable)
    void Activate();
};
