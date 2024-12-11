#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CustomizationAssetLoadedSignalDelegate.h"
#include "CustomizationAssetsBegunLoadingDelegate.h"
#include "ECharacterCustomizationType.h"
#include "SingleCustomizationAssetLoadedSignalDelegate.h"
#include "Templates/SubclassOf.h"
#include "AstroCustomizationTileGridWidget.generated.h"

class UAstroCharacterHat;
class UAstroCharacterOverlayPattern;
class UAstroCharacterPalette;
class UAstroCharacterSuit;
class UAstroCustomizationItemTileWidget;
class UAstroCustomizationTileWidget;
class UAstroEmoteDefinition;
class UAstroOutfitTileWidget;
class UAstroPhotoFilter;
class UAstroVisorMaterial;
class UWrapBox;

UCLASS(Blueprintable, EditInlineNew)
class ASTRO_API UAstroCustomizationTileGridWidget : public UUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCustomizationAssetsBegunLoading OnCustomizationAssetsBegunLoading;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCustomizationAssetLoadedSignal OnCustomizationAssetsLoaded;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSingleCustomizationAssetLoadedSignal OnCustomizationAssetLoaded;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UAstroCharacterSuit*> Suits;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UAstroVisorMaterial*> Visors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UAstroCharacterPalette*> Palettes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UAstroCharacterOverlayPattern*> Overlays;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UAstroCharacterHat*> Hats;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UAstroCharacterHat*> Masks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UAstroPhotoFilter*> Filters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UAstroEmoteDefinition*> Emotes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 LoadedAssetCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAstroCustomizationTileWidget> CustomizationTileWidgetClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAstroOutfitTileWidget> OutfitTileWidgetClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UAstroCustomizationTileWidget*> CustomizationTileWidgetPool;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UAstroOutfitTileWidget*> OutfitTileWidgetPool;
    
public:
    UAstroCustomizationTileGridWidget();

protected:
    UFUNCTION(BlueprintCallable)
    void ReturnOutfitTile(UAstroOutfitTileWidget* TileWidget);
    
    UFUNCTION(BlueprintCallable)
    void ReturnCustomizationTile(UAstroCustomizationTileWidget* TileWidget);
    
    UFUNCTION(BlueprintCallable)
    UAstroOutfitTileWidget* RequestOutfitTile();
    
    UFUNCTION(BlueprintCallable)
    UAstroCustomizationTileWidget* RequestCustomizationTile();
    
public:
    UFUNCTION(BlueprintCallable)
    void AsyncLoadCustomizationAssetType(ECharacterCustomizationType customizationType);
    
    UFUNCTION(BlueprintCallable)
    void AssetLoadedCallback(ECharacterCustomizationType customizationType, int32 Index);
    
    UFUNCTION(BlueprintCallable)
    void AddCustomizationTileAtDesiredIndex(UWrapBox* WrapBoxContainer, UAstroCustomizationItemTileWidget* Tile);
    
};

