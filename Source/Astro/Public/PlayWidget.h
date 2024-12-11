#pragma once
#include "CoreMinimal.h"
#include "Layout/Geometry.h"
#include "Blueprint/UserWidget.h"
#include "PlayWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ASTRO_API UPlayWidget : public UUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HealthImageOpacity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ImmunityImageOpacity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGeometry CachedGeometry;
    
    UPlayWidget();

};

