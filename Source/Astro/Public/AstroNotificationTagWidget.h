#pragma once
#include "CoreMinimal.h"
#include "AstroUICardWidget.h"
#include "AstroNotificationTagWidgetDisplayData.h"
#include "AstroNotificationTagWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ASTRO_API UAstroNotificationTagWidget : public UAstroUICardWidget
{
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    float ElapsedAnimationTimeNormalized;

    UPROPERTY(EditAnywhere)
    float AnimationDuration;

    UPROPERTY(EditDefaultsOnly)
    float DriftIncrement;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    float DriftTarget;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FAstroNotificationTagWidgetDisplayData DisplayData;

public:
    UAstroNotificationTagWidget();

protected:
    UFUNCTION(BlueprintImplementableEvent)
    void UpdateAnimationVisuals(float DeltaTime);
};
