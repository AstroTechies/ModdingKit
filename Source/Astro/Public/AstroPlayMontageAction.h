#pragma once
#include "CoreMinimal.h"
#include "AstroAction.h"
#include "AstroPlayMontageAction.generated.h"

class UAnimMontage;

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API UAstroPlayMontageAction : public UAstroAction
{
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditDefaultsOnly)
    UAnimMontage *Montage;

    UPROPERTY(EditDefaultsOnly)
    FName StartSection;

    UPROPERTY(EditDefaultsOnly)
    float PlayRate;

    UPROPERTY(EditDefaultsOnly)
    uint8 bShouldSuppressLookInput : 1;

    UPROPERTY(EditDefaultsOnly)
    uint8 bShouldSuppressMoveInput : 1;

    UPROPERTY(EditDefaultsOnly)
    uint8 bChooseStartSectionAtRandom : 1;

public:
    UAstroPlayMontageAction();
    UFUNCTION(BlueprintCallable)
    void SetMontage(UAnimMontage *NewMontage);

    UFUNCTION()
    void OnSingleAnimCustomNotify(FName NotifyName);

    UFUNCTION()
    void OnMontageTaskInterrupted();

    UFUNCTION()
    void OnMontageTaskFailedToStart();

    UFUNCTION()
    void OnMontageTaskCompleted();
};
