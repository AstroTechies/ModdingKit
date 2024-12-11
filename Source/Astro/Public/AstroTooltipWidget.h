#pragma once
#include "CoreMinimal.h"
#include "AstroUICardWidget.h"
#include "ETooltipAnimation.h"
#include "ETooltipState.h"
#include "InteractionPromptEntryData.h"
#include "TooltipWidgetDisplayData.h"
#include "AstroTooltipWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ASTRO_API UAstroTooltipWidget : public UAstroUICardWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTooltipWidgetDisplayData TooltipWidgetDisplayData;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ExpandBadgeTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CollapseBadgeTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ExpandDetailsTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CollapseDetailsTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ETooltipState CurrentState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ETooltipAnimation CurrentAnimation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float AnimationProgressRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    uint8 bUseInteractionVisiblityOverriden: 1;
    
public:
    UAstroTooltipWidget();

protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UpdateUseInteractionVisiblityOverride();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UpdateTooltipDataForInteractionPromptsWithoutChangingLayout(FTooltipWidgetDisplayData NewTooltipWidgetDisplayData);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UpdateTooltipAnimation();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnTextContentChanged();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnStateChanged();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnAnimationChanged();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool HasValidInteractionPromptInArray(const TArray<FInteractionPromptEntryData>& InteractionPromptData);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasBadge() const;
    
};

