#pragma once
#include "CoreMinimal.h"
#include "GameplayTask.h"
#include "SignalDelegate.h"
// CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=OnSingleAnimCustomNotify__DelegateSignature -FallbackName=OnSingleAnimCustomNotifyDelegate
#include "AstroPlayMontageTask.generated.h"

class UAnimMontage;
class UAstroPlayMontageTask;
class UAstroAction;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSingleAnimCustomNotify, FName, NotifyName);

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API UAstroPlayMontageTask : public UGameplayTask
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable)
    FSignal OnFailedToStart;

    UPROPERTY(BlueprintAssignable)
    FSignal OnInterrupted;

    UPROPERTY(BlueprintAssignable)
    FSignal OnCompleted;

    UPROPERTY(BlueprintAssignable)
    FOnSingleAnimCustomNotify OnSingleAnimCustomNotify;

    UAstroPlayMontageTask(const FObjectInitializer &ObjectInitializer);

protected:
    UFUNCTION()
    void RouteSingleAnimCustomNotify(FName NotifyName);

public:
    UFUNCTION()
    void OnMontageEnded(UAnimMontage *Montage, bool bInterrupted);

protected:
    UFUNCTION()
    void OnAnimInitialized();

public:
    UFUNCTION(BlueprintCallable)
    static UAstroPlayMontageTask *CreateAstroPlayMontageTask(UAstroAction *OwningAction, FName TaskInstanceName, UAnimMontage *Montage, float PlayRate, FName StartSection);
};
