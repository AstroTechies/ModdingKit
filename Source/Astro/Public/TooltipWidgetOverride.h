#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector2D -FallbackName=Vector2D
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ComponentReference -FallbackName=ComponentReference
#include "ETooltipVisibilityControl.h"
#include "TooltipProximityBadgeVisibilityData.h"
#include "TooltipWidgetDisplayData.h"
#include "TooltipWidgetOverride.generated.h"

USTRUCT(BlueprintType)
struct FTooltipWidgetOverride {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ETooltipVisibilityControl VisibilityControlOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bApplyAnchorReferenceComponentOverride: 1;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference AnchorReferenceComponentOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bApplyScreenOffsetOverride: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D ScreenOffsetOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bRemainsVisibleWhenHeldOverride: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bSuppressOtherTooltipsWhenExpandedOverride: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bOverrideUseAndExaminePrompts: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTooltipProximityBadgeVisibilityData ProximityVisibilityDataOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTooltipWidgetDisplayData DisplayDataOverride;
    
    ASTRO_API FTooltipWidgetOverride();
};

