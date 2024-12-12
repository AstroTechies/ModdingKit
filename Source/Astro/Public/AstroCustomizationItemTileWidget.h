#pragma once
#include "CoreMinimal.h"
#include "AstroCustomizationTileWidget.h"
#include "SignalDelegate.h"
#include "AstroCustomizationItemTileWidget.generated.h"

class UAstroCustomizationItem;
class UObject;

UCLASS(Blueprintable, EditInlineNew)
class ASTRO_API UAstroCustomizationItemTileWidget : public UAstroCustomizationTileWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAstroCustomizationItem* customizationItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsLocked;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsNew;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 DesiredGridIndex;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnSoftReferencesLoaded;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UObject* TileBackgroundTexture;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UObject* TileMiddlegroundTexture;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UObject* TileForegroundTexture;
    
public:
    UAstroCustomizationItemTileWidget();

protected:
    UFUNCTION(BlueprintCallable)
    void SetTexturesDeferred();
    
};

