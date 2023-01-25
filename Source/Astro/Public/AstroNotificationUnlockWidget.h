#pragma once
#include "CoreMinimal.h"
#include "AstroNotificationUnlockDisplayData.h"
#include "SignalDelegate.h"
#include "UserWidgetBlueprintDesignable.h"
#include "AstroNotificationUnlockWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ASTRO_API UAstroNotificationUnlockWidget : public UUserWidgetBlueprintDesignable {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAstroNotificationUnlockDisplayData DisplayData;
    
private:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnMaxLifetimeReached;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DriftIncrement;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SpawningDriftOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxLifetime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MagicDriftSpeed;
    
public:
    UAstroNotificationUnlockWidget();
private:
    UFUNCTION(BlueprintCallable)
    void MarkNotificationForDestruction();
    
};

