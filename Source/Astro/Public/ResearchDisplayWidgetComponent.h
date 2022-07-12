#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=UMG -ObjectName=WidgetComponent -FallbackName=WidgetComponent
#include "Components/WidgetComponent.h"
#include "ResearchDisplayWidgetComponent.generated.h"

class UResearchDisplayWidget;

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UResearchDisplayWidgetComponent : public UWidgetComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    UResearchDisplayWidget* ResearchDisplayWidget;
    
public:
    UResearchDisplayWidgetComponent();
};

