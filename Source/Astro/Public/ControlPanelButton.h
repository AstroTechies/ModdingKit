#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnableSignalDelegate.h"
#include "SignalDelegate.h"
#include "ControlPanelButton.generated.h"

UCLASS(Abstract, Blueprintable)
class ASTRO_API AControlPanelButton : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnButtonPressed;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnableSignal OnButtonArmedChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnableSignal OnButtonHoveredChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnableSignal OnButtonCoverHoveredChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnableSignal OnButtonEnabledChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bHasCover: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bCloseCoverOnUnHover: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bCoverOpenedWhenEnabled: 1;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bButtonEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bButtonArmed;
    
public:
    AControlPanelButton(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SetButtonEnabled(bool Enabled);
    
    UFUNCTION(BlueprintCallable)
    void SetButtonArmed(bool Armed);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetButtonEnabled();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetButtonArmed();
    
    UFUNCTION(BlueprintCallable)
    void DoUnHoverButton();
    
    UFUNCTION(BlueprintCallable)
    void DoHoverButton();
    
    UFUNCTION(BlueprintCallable)
    void DoButtonPress();
    
};

