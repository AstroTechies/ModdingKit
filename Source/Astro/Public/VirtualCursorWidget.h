#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "VirtualCursorWidget.generated.h"

UCLASS(Blueprintable, Abstract, EditInlineNew)
class ASTRO_API UVirtualCursorWidget : public UUserWidget
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Transient, meta = (AllowPrivateAccess = true))
    bool IsHoveringOverInteractable;

    UVirtualCursorWidget();
};
