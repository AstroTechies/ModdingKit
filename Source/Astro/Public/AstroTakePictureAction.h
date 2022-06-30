#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "AstroAction.h"
#include "SignalDelegate.h"
#include "AstroTakePictureAction.generated.h"

class UWandererPhotoWidget;
class APlayerController;

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API UAstroTakePictureAction : public UAstroAction
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable)
    FSignal OnTakePictureCountdownPing;

    UPROPERTY(BlueprintAssignable)
    FSignal OnPictureTaken;

protected:
    UPROPERTY(EditDefaultsOnly)
    TSubclassOf<UWandererPhotoWidget> PhotoWidgetType;

    UPROPERTY(EditDefaultsOnly)
    float PictureImageCaptureDelay;

    UPROPERTY(EditDefaultsOnly)
    float PhotoWidgetDisplayDelay;

    UPROPERTY(EditDefaultsOnly)
    uint8 bPhotoWidgetForInstigatorOnly : 1;

    UPROPERTY(EditDefaultsOnly)
    float DisplayPhotoWidgetForPlayersWithinDistance;

public:
    UAstroTakePictureAction();
    UFUNCTION(BlueprintCallable)
    void SetInstigator(APlayerController *Instigator);

protected:
    UFUNCTION()
    void OnTakePictureTaskCompleted();

    UFUNCTION()
    void OnPictureImageCaptureDelayComplete();

    UFUNCTION()
    void OnPhotoWidgetDisplayDelayComplete();

    UFUNCTION()
    void BroadcastTakePictureCountdownPing();
};
