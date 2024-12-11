#pragma once
#include "CoreMinimal.h"
#include "AstroPlayMontageAction.h"
#include "SignalDelegate.h"
#include "Templates/SubclassOf.h"
#include "AstroTakePictureEmoteAction.generated.h"

class UWandererPhotoWidget;

UCLASS(Blueprintable)
class ASTRO_API UAstroTakePictureEmoteAction : public UAstroPlayMontageAction {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnPictureTaken;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UWandererPhotoWidget> PhotoWidgetType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DisplayPhotoWidgetForPlayersWithinDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bPhotoWidgetForInstigatorOnly: 1;
    
public:
    UAstroTakePictureEmoteAction();

protected:
    UFUNCTION(BlueprintCallable)
    void OnTakePictureTaskCompleted();
    
};

