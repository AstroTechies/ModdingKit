#pragma once
#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "ResearchDisplayWidgetComponent.generated.h"

class UResearchDisplayWidget;

UCLASS(Blueprintable, EditInlineNew, meta = (BlueprintSpawnableComponent))
class ASTRO_API UResearchDisplayWidgetComponent : public UWidgetComponent
{
    GENERATED_BODY()
public:
protected:
    UPROPERTY(Export, Transient)
    UResearchDisplayWidget *ResearchDisplayWidget;

public:
    UResearchDisplayWidgetComponent();
};
