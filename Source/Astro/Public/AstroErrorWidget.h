#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AstroErrorWidget.generated.h"

UCLASS(Blueprintable, Abstract, EditInlineNew)
class ASTRO_API UAstroErrorWidget : public UUserWidget
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Transient, meta = (AllowPrivateAccess = true))
    FString Message;

protected:
    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    float Timer;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float DefaultTimeToDisplay;

public:
    UAstroErrorWidget();
};
