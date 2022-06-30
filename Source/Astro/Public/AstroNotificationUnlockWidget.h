#pragma once
#include "CoreMinimal.h"
#include "UserWidgetBlueprintDesignable.h"
#include "AstroNotificationUnlockDisplayData.h"
#include "SignalDelegate.h"
#include "AstroNotificationUnlockWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ASTRO_API UAstroNotificationUnlockWidget : public UUserWidgetBlueprintDesignable
{
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FAstroNotificationUnlockDisplayData DisplayData;

private:
    UPROPERTY(BlueprintAssignable)
    FSignal OnMaxLifetimeReached;

    UPROPERTY(EditAnywhere)
    float DriftIncrement;

    UPROPERTY(EditAnywhere)
    float SpawningDriftOffset;

    UPROPERTY(EditAnywhere)
    float MaxLifetime;

    UPROPERTY(EditAnywhere)
    float MagicDriftSpeed;

public:
    UAstroNotificationUnlockWidget();

private:
    UFUNCTION(BlueprintCallable)
    void MarkNotificationForDestruction();
};
