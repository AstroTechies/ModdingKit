#pragma once
#include "CoreMinimal.h"
#include "UserWidgetBlueprintDesignable.h"
#include "WandererPhotoWidget.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UWandererPhotoWidget : public UUserWidgetBlueprintDesignable {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bShowFilterSelection: 1;
    
    UWandererPhotoWidget();

    UFUNCTION(BlueprintCallable)
    void ClosePhotoWidget();
    
};

