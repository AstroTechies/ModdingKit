#pragma once
#include "CoreMinimal.h"
#include "AstroGameMenuFocusItemWidget.h"
#include "AstroGameMenuTabBarButtonWidget.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UAstroGameMenuTabBarButtonWidget : public UAstroGameMenuFocusItemWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsAutoUsedWhenTabNavigatedTo;
    
    UAstroGameMenuTabBarButtonWidget();

};

