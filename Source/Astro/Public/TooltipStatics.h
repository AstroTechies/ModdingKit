#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
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

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UTooltipComponent* GetDefaultTooltipComponentForActor(AActor* TooltipOwner);
    
    UFUNCTION(BlueprintCallable)
    static FTooltipWidgetDisplayData DuplicateTooltipDisplayDataAndAppendInteractionPrompts(FTooltipWidgetDisplayData DataToCopy, const TArray<FInteractionPromptEntryData>& InteractionPromptDataToAdd);
    
};

