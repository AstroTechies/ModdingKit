#pragma once
#include "CoreMinimal.h"
#include "AstroGameMenuFocusItemWidget.h"
#include "Templates/SubclassOf.h"
#include "AstroGameMenuTabBarButtonWidget.generated.h"

class UAstroGameMenuSubPaneWidget;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UAstroGameMenuTabBarButtonWidget : public UAstroGameMenuFocusItemWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsAutoUsedWhenTabNavigatedTo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAstroGameMenuSubPaneWidget> SubPaneLeftClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAstroGameMenuSubPaneWidget> SubPaneRightClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 TabBarSelectionIndex;
    
    UAstroGameMenuTabBarButtonWidget();

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    bool GetShouldHideTab();
    
};

