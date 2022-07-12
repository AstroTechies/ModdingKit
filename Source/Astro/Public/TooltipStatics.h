#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=BlueprintFunctionLibrary -FallbackName=BlueprintFunctionLibrary
#include "InteractionPromptEntryData.h"
#include "TooltipWidgetDisplayData.h"
#include "TooltipStatics.generated.h"

class AActor;
class UTooltipComponent;

UCLASS(Blueprintable)
class ASTRO_API UTooltipStatics : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UTooltipStatics();
    UFUNCTION(BlueprintPure)
    static UTooltipComponent* GetDefaultTooltipComponentForActor(AActor* TooltipOwner);
    
    UFUNCTION(BlueprintCallable)
    static FTooltipWidgetDisplayData DuplicateTooltipDisplayDataAndAppendInteractionPrompts(FTooltipWidgetDisplayData DataToCopy, const TArray<FInteractionPromptEntryData>& InteractionPromptDataToAdd);
    
};

