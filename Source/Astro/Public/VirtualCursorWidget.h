#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=UMG -ObjectName=UserWidget -FallbackName=UserWidget
#include "Blueprint/UserWidget.h"
#include "VirtualCursorWidget.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class ASTRO_API UVirtualCursorWidget : public UUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool IsHoveringOverInteractable;
    
    UVirtualCursorWidget();
};

