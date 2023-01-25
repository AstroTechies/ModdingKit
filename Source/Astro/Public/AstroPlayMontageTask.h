#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=OnSingleAnimCustomNotify__DelegateSignature -FallbackName=OnSingleAnimCustomNotifyDelegate
#include "GameplayTask.h"
#include "SignalDelegate.h"
#include "AstroPlayMontageTask.generated.h"

class UAnimMontage;
class UAstroAction;
class UAstroPlayMontageTask;

UCLASS(Blueprintable)
class ASTRO_API UAstroPlayMontageTask : public UGameplayTask {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnFailedToStart;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnInterrupted;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnCompleted;
    
    UAstroPlayMontageTask();
protected:
    UFUNCTION(BlueprintCallable)
    void RouteSingleAnimCustomNotify(FName NotifyName);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnMontageEnded(UAnimMontage* Montage, bool bInterrupted);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnAnimInitialized();
    
public:
    UFUNCTION(BlueprintCallable)
    static UAstroPlayMontageTask* CreateAstroPlayMontageTask(UAstroAction* OwningAction, FName TaskInstanceName, UAnimMontage* Montage, float PlayRate, FName StartSection);
    
};

