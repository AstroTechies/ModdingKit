#pragma once
#include "CoreMinimal.h"
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

