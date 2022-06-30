#pragma once
#include "CoreMinimal.h"
#include "ETooltipAnimation.h"
#include "AstroUICardWidget.h"
#include "TooltipWidgetDisplayData.h"
#include "InteractionPromptEntryData.h"
#include "ETooltipState.h"
#include "AstroTooltipWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ASTRO_API UAstroTooltipWidget : public UAstroUICardWidget
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FTooltipWidgetDisplayData TooltipWidgetDisplayData;

protected:
    UPROPERTY(EditAnywhere)
    float ExpandBadgeTime;

    UPROPERTY(EditAnywhere)
    float CollapseBadgeTime;

    UPROPERTY(EditAnywhere)
    float ExpandDetailsTime;

    UPROPERTY(EditAnywhere)
    float CollapseDetailsTime;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    ETooltipState CurrentState;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    ETooltipAnimation CurrentAnimation;

    UPROPERTY(BlueprintReadWrite, Transient, meta = (AllowPrivateAccess = true))
    float AnimationProgressRatio;

    UPROPERTY(BlueprintReadWrite, Transient, meta = (AllowPrivateAccess = true))
    uint8 bUseInteractionVisiblityOverriden : 1;

public:
    UAstroTooltipWidget();

protected:
    UFUNCTION(BlueprintImplementableEvent)
    void UpdateUseInteractionVisiblityOverride();

public:
    UFUNCTION(BlueprintImplementableEvent)
    void UpdateTooltipDataForInteractionPromptsWithoutChangingLayout(FTooltipWidgetDisplayData NewTooltipWidgetDisplayData);

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UpdateTooltipAnimation();

    UFUNCTION(BlueprintImplementableEvent)
    void OnTextContentChanged();

    UFUNCTION(BlueprintImplementableEvent)
    void OnStateChanged();

    UFUNCTION(BlueprintImplementableEvent)
    void OnAnimationChanged();

    UFUNCTION(BlueprintPure)
    static bool HasValidInteractionPromptInArray(const TArray<FInteractionPromptEntryData> &InteractionPromptData);

    UFUNCTION(BlueprintPure)
    bool HasBadge() const;
};
