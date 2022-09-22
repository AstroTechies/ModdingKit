#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "AstroAction.h"
#include "SignalDelegate.h"
#include "AstroTakePictureAction.generated.h"

class UWandererPhotoWidget;
class APlayerController;

UCLASS(Blueprintable)
class ASTRO_API UAstroTakePictureAction : public UAstroAction {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnTakePictureCountdownPing;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnPictureTaken;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UWandererPhotoWidget> PhotoWidgetType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PictureImageCaptureDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PhotoWidgetDisplayDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bPhotoWidgetForInstigatorOnly: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DisplayPhotoWidgetForPlayersWithinDistance;
    
public:
    UAstroTakePictureAction();
    UFUNCTION(BlueprintCallable)
    void SetInstigator(APlayerController* Instigator);
    
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

