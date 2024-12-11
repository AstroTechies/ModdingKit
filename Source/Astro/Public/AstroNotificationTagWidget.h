#pragma once
#include "CoreMinimal.h"
#include "AstroNotificationTagWidgetDisplayData.h"
#include "AstroUICardWidget.h"
#include "AstroNotificationTagWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ASTRO_API UAstroNotificationTagWidget : public UAstroUICardWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ElapsedAnimationTimeNormalized;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AnimationDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DriftIncrement;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DriftTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAstroNotificationTagWidgetDisplayData DisplayData;
    
public:
    UAstroNotificationTagWidget();

protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UpdateAnimationVisuals(float DeltaTime);
    
};

