#pragma once
#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "ResearchDisplayWidgetComponent.generated.h"

class UResearchDisplayWidget;

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UResearchDisplayWidgetComponent : public UWidgetComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UResearchDisplayWidget* ResearchDisplayWidget;
    
public:
    UResearchDisplayWidgetComponent();
};

