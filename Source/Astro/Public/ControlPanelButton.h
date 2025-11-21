#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ControlPanelButton.generated.h"

class AControlPanelButton;

UCLASS(Abstract, Blueprintable)
class ASTRO_API AControlPanelButton : public AActor {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FButtonState, bool, Enable, AControlPanelButton*, Actor);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FButtonEvent, AControlPanelButton*, Actor);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FButtonEvent OnButtonPressed;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FButtonState OnButtonArmedChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FButtonState OnButtonHoveredChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FButtonState OnButtonCoverHoveredChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FButtonState OnButtonEnabledChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Name;
    
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

