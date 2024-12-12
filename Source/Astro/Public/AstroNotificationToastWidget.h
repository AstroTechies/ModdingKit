#pragma once
#include "CoreMinimal.h"
#include "AstroNotificationToastDisplayData.h"
#include "SignalDelegate.h"
#include "UserWidgetBlueprintDesignable.h"
#include "AstroNotificationToastWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ASTRO_API UAstroNotificationToastWidget : public UUserWidgetBlueprintDesignable {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bWidgetShouldRemainPresented: 1;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAstroNotificationToastDisplayData DisplayData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxLifetime;
    
private:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnMaxLifetimeReached;
    
public:
    UAstroNotificationToastWidget();

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetShouldStayPresented(bool bShouldRetainBiomeToast);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void PresentToast();
    
private:
    UFUNCTION(BlueprintCallable)
    void MarkNotificationForDestruction();
    
};

