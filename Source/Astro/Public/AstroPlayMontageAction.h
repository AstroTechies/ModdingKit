#pragma once
#include "CoreMinimal.h"
#include "AstroAction.h"
#include "AstroPlayMontageAction.generated.h"

class UAnimMontage;

UCLASS(Blueprintable)
class ASTRO_API UAstroPlayMontageAction : public UAstroAction {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimMontage* Montage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName StartSection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PlayRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bShouldSuppressLookInput: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bShouldSuppressMoveInput: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bChooseStartSectionAtRandom: 1;
    
public:
    UAstroPlayMontageAction();

    UFUNCTION(BlueprintCallable)
    void SetMontage(UAnimMontage* NewMontage);
    
    UFUNCTION(BlueprintCallable)
    void OnSingleAnimCustomNotify(FName NotifyName);
    
    UFUNCTION(BlueprintCallable)
    void OnMontageTaskInterrupted();
    
    UFUNCTION(BlueprintCallable)
    void OnMontageTaskFailedToStart();
    
    UFUNCTION(BlueprintCallable)
    void OnMontageTaskCompleted();
    
};

