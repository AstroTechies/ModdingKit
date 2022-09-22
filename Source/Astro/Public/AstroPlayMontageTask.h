#pragma once
#include "CoreMinimal.h"
#include "GameplayTask.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=OnSingleAnimCustomNotify__DelegateSignature -FallbackName=OnSingleAnimCustomNotifyDelegate
//CROSS-MODULE INCLUDE V2: -ModuleName=GameplayTasks -ObjectName=GameplayTask -FallbackName=GameplayTask
#include "SignalDelegate.h"
#include "AstroPlayMontageTask.generated.h"

class UAstroPlayMontageTask;
class UAnimMontage;
class UAstroAction;

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
    UFUNCTION()
    void RouteSingleAnimCustomNotify(FName NotifyName);
    
public:
    UFUNCTION()
    void OnMontageEnded(UAnimMontage* Montage, bool bInterrupted);
    
protected:
    UFUNCTION()
    void OnAnimInitialized();
    
public:
    UFUNCTION(BlueprintCallable)
    static UAstroPlayMontageTask* CreateAstroPlayMontageTask(UAstroAction* OwningAction, FName TaskInstanceName, UAnimMontage* Montage, float PlayRate, FName StartSection);
    
};

