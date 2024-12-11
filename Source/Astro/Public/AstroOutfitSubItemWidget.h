#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AstroOutfitSubItemWidget.generated.h"

class UAstroCustomizationItem;

UCLASS(Blueprintable, EditInlineNew)
class ASTRO_API UAstroOutfitSubItemWidget : public UUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAstroCustomizationItem* customizationItem;
    
    UAstroOutfitSubItemWidget();

};

