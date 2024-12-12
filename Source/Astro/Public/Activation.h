#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "EnableSignalDelegate.h"
#include "SignalActivationBinding.h"
#include "SignalDelegate.h"
#include "Activation.generated.h"

class UActivation;

UCLASS(Blueprintable)
class UActivation : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnActivate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnDeactivate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnableSignal OnChange;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool m_bActive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSignalActivationBinding> Bindings;
    
public:
    UActivation();

    UFUNCTION(BlueprintCallable)
    bool Update(bool Active);
    
    UFUNCTION(BlueprintCallable)
    void UnbindTo(UActivation* Other);
    
    UFUNCTION(BlueprintCallable)
    void Toggle();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsActive();
    
    UFUNCTION(BlueprintCallable)
    void Deactivate();
    
    UFUNCTION(BlueprintCallable)
    void BindTo(UActivation* Other);
    
    UFUNCTION(BlueprintCallable)
    void Activate();
    
};

