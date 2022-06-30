#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "IndicatorMeshDefinition.h"
#include "GateObjectIndicatorDefinition.generated.h"

class UObject;
class UMaterialInterface;

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API UGateObjectIndicatorDefinition : public UDataAsset
{
    GENERATED_BODY()
public:
    UPROPERTY(EditDefaultsOnly)
    FText TooltipSubtitle;

    UPROPERTY(EditDefaultsOnly)
    UObject *TooltipBadge;

    UPROPERTY(EditDefaultsOnly)
    UObject *TooltipBadgeBackground;

    UPROPERTY(EditDefaultsOnly)
    FIndicatorMeshDefinition IndicatorMeshDefinition;

    UPROPERTY(EditDefaultsOnly)
    UMaterialInterface *InertIndicatorMaterial;

    UPROPERTY(EditDefaultsOnly)
    UMaterialInterface *ActiveIndicatorMaterial;

    UPROPERTY(EditDefaultsOnly)
    FName PlayerIndicatorSocketName;

    UGateObjectIndicatorDefinition();
};
