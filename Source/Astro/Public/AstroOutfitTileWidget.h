#pragma once
#include "CoreMinimal.h"
//#include "AstroPlayFabUserOutfit.h"
#include "UObject/NoExportTypes.h"
#include "AstroCharacterCustomization.h"
#include "AstroCustomizationSoftReferences.h"
#include "AstroInteractableTileWidget.h"
#include "SignalDelegate.h"
#include "AstroOutfitTileWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ASTRO_API UAstroOutfitTileWidget : public UAstroInteractableTileWidget {
    GENERATED_BODY()
public:
//    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
//    FAstroPlayFabUserOutfit UserOutfit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGuid OutfitGuid;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnSoftReferencesLoaded;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAstroCustomizationSoftReferences CustomizationSoftReferences;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAstroCharacterCustomization CharacterCustomization;
    
public:
    UAstroOutfitTileWidget();

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Setup();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Sanitize();
    
protected:
    UFUNCTION(BlueprintCallable)
    void AsyncLoadSoftReferences();
    
    UFUNCTION(BlueprintCallable)
    void AsyncLoadComplete();
    
};

