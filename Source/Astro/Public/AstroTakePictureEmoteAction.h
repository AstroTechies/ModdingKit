#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "AstroPlayMontageAction.h"
#include "SignalDelegate.h"
#include "AstroTakePictureEmoteAction.generated.h"

class UWandererPhotoWidget;

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API UAstroTakePictureEmoteAction : public UAstroPlayMontageAction
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable)
    FSignal OnPictureTaken;

protected:
    UPROPERTY(EditDefaultsOnly)
    TSubclassOf<UWandererPhotoWidget> PhotoWidgetType;

    UPROPERTY(EditDefaultsOnly)
    float DisplayPhotoWidgetForPlayersWithinDistance;

    UPROPERTY(EditDefaultsOnly)
    uint8 bPhotoWidgetForInstigatorOnly : 1;

public:
    UAstroTakePictureEmoteAction();

protected:
    UFUNCTION()
    void OnTakePictureTaskCompleted();
};
