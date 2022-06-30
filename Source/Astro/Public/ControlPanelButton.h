#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SignalDelegate.h"
#include "EnableSignalDelegate.h"
#include "ControlPanelButton.generated.h"

UCLASS(Blueprintable, Abstract)
class ASTRO_API AControlPanelButton : public AActor
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable)
    FSignal OnButtonPressed;

    UPROPERTY(BlueprintAssignable)
    FEnableSignal OnButtonArmedChanged;

    UPROPERTY(BlueprintAssignable)
    FEnableSignal OnButtonHoveredChanged;

    UPROPERTY(BlueprintAssignable)
    FEnableSignal OnButtonCoverHoveredChanged;

    UPROPERTY(BlueprintAssignable)
    FEnableSignal OnButtonEnabledChanged;

    UPROPERTY(EditDefaultsOnly)
    uint8 bHasCover : 1;

    UPROPERTY(EditDefaultsOnly)
    uint8 bCloseCoverOnUnHover : 1;

    UPROPERTY(EditDefaultsOnly)
    uint8 bCoverOpenedWhenEnabled : 1;

protected:
    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    bool bButtonEnabled;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    bool bButtonArmed;

public:
    AControlPanelButton();
    UFUNCTION(BlueprintCallable)
    void SetButtonEnabled(bool Enabled);

    UFUNCTION(BlueprintCallable)
    void SetButtonArmed(bool Armed);

    UFUNCTION(BlueprintPure)
    bool GetButtonEnabled();

    UFUNCTION(BlueprintPure)
    bool GetButtonArmed();

    UFUNCTION(BlueprintCallable)
    void DoUnHoverButton();

    UFUNCTION(BlueprintCallable)
    void DoHoverButton();

    UFUNCTION(BlueprintCallable)
    void DoButtonPress();
};
