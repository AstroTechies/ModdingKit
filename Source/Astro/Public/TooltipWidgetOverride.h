#pragma once
#include "CoreMinimal.h"
#include "ETooltipVisibilityControl.h"
#include "Engine/EngineTypes.h"
#include "UObject/NoExportTypes.h"
#include "TooltipProximityBadgeVisibilityData.h"
#include "TooltipWidgetDisplayData.h"
#include "TooltipWidgetOverride.generated.h"

USTRUCT(BlueprintType)
struct FTooltipWidgetOverride {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    FName Name;
    
    UPROPERTY(EditAnywhere)
    ETooltipVisibilityControl VisibilityControlOverride;
    
    UPROPERTY(EditAnywhere)
    uint8 bApplyAnchorReferenceComponentOverride: 1;
    
    UPROPERTY(EditAnywhere)
    FComponentReference AnchorReferenceComponentOverride;
    
    UPROPERTY(EditAnywhere)
    uint8 bApplyScreenOffsetOverride: 1;
    
    UPROPERTY(EditAnywhere)
    FVector2D ScreenOffsetOverride;
    
    UPROPERTY(EditAnywhere)
    uint8 bRemainsVisibleWhenHeldOverride: 1;
    
    UPROPERTY(EditAnywhere)
    uint8 bSuppressOtherTooltipsWhenExpandedOverride: 1;
    
    UPROPERTY(EditAnywhere)
    uint8 bOverrideUseAndExaminePrompts: 1;
    
    UPROPERTY(EditAnywhere)
    FTooltipProximityBadgeVisibilityData ProximityVisibilityDataOverride;
    
    UPROPERTY(EditAnywhere)
    FTooltipWidgetDisplayData DisplayDataOverride;
    
    ASTRO_API FTooltipWidgetOverride();
};

