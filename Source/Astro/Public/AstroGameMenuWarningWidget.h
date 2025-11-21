#pragma once
#include "CoreMinimal.h"
#include "AstroGameMenuFocusItemWidget.h"
#include "SignalDelegate.h"
#include "AstroGameMenuWarningWidget.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UAstroGameMenuWarningWidget : public UAstroGameMenuFocusItemWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText primaryText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText secondaryText;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnWarningTextSet;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bIsFadedOut: 1;
    
    UAstroGameMenuWarningWidget();

    UFUNCTION(BlueprintCallable)
    void SetWarningText(FText NewPrimaryText, FText NewSecondaryText);
    
    UFUNCTION(BlueprintCallable)
    void SetSecondaryWarningText(FText NewSecondaryText);
    
    UFUNCTION(BlueprintCallable)
    void SetPrimaryWarningText(FText NewPrimaryText);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    float FadeOutWidget();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    float FadeInWidget();
    
};

