#pragma once
#include "CoreMinimal.h"
#include "Layout/Geometry.h"
#include "Blueprint/UserWidget.h"
#include "PlayWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ASTRO_API UPlayWidget : public UUserWidget
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    float HealthImageOpacity;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    float ImmunityImageOpacity;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    FGeometry CachedGeometry;

    UPlayWidget();
};
