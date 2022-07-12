#pragma once
#include "CoreMinimal.h"
#include "UserWidgetBlueprintDesignable.h"
#include "ReconnectWidget.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class ASTRO_API UReconnectWidget : public UUserWidgetBlueprintDesignable {
    GENERATED_BODY()
public:
    UReconnectWidget();
};

