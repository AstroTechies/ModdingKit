#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TooltipManager.generated.h"

class UPrimitiveComponent;
class UTooltipComponent;

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class ASTRO_API UTooltipManager : public UActorComponent
{
    GENERATED_BODY()
public:
private:
    UPROPERTY(Export, Transient)
    TMap<UPrimitiveComponent *, UTooltipComponent *> InputRespondingTooltips;

    UPROPERTY(Export, Transient)
    TArray<UTooltipComponent *> ActiveTooltips;

    UPROPERTY(Export, Transient)
    TArray<UTooltipComponent *> LiveTooltips;

    UPROPERTY(Export, Transient)
    UTooltipComponent *ExclusiveExpansionTooltip;

    UPROPERTY(Export, Transient)
    UTooltipComponent *CursorOverTooltip;

    UPROPERTY(Transient)
    uint8 AllTooltipsDisabled : 1;

    UPROPERTY(Transient)
    uint8 BelongsToLocalController : 1;

public:
    UTooltipManager();

private:
    UFUNCTION()
    void OnTooltipPrimitiveEndCursorOver(UPrimitiveComponent *TooltipPrimitive);

    UFUNCTION()
    void OnTooltipPrimitiveBeginCursorOver(UPrimitiveComponent *TooltipPrimitive);

public:
    UFUNCTION()
    void OnExclusiveExpansionTooltipOverrideChanged();
};
