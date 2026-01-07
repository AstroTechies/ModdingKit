#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ControlSymbol.h"
#include "EAstroGameMenuTutoriaSlideCardKey.h"
#include "EItemDLCEntitlementLock.h"
#include "EItemStorageBehavior.h"
#include "Recipe.h"
#include "Templates/SubclassOf.h"
#include "ItemType.generated.h"

class AActor;
class UItemCatalogData;
class UItemType;
class UMegastructureRecipe;
class UResearchSubjectDefinition;
class UStaticMesh;
class UTexture;
class UTexture2D;

UCLASS(Blueprintable)
class ASTRO_API UItemType : public UControlSymbol {
    GENERATED_BODY()
public:
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    // Safe to leave checked 
    uint8 bDestroyOnAddDeformation: 1;
    
    UPROPERTY(SimpleDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    // Is this indestructible?
    uint8 Indestructible: 1;
    
    UPROPERTY(SimpleDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    // Whether or not the item contributes to an explosion, like Hydrazine does
    uint8 IsVolatile: 1;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    // Is this a power resource? Generally leave unchecked 
    uint8 IsPower: 1;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    // Is this an oxygen resource? Generally leave unchecked 
    uint8 IsOxygen: 1;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bIsMegastructure: 1;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 CreativeSpawnEmpty: 1;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EItemDLCEntitlementLock DLCEntitlementLock;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 UseSquareIconBackground: 1;
    
    UPROPERTY(SimpleDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    // Can this be put into a shredder?
    uint8 bCanBeScrapped: 1;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bApplyTintToHarvestActors: 1;
    
    UPROPERTY(SimpleDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    // Can this item not be packaged with a packager?
    uint8 bIsUnrepackageable: 1;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EItemStorageBehavior InternalStorageBehavior;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ItemRepackageAudioSwitch;
    
    UPROPERTY(SimpleDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    // What items can go into this container?
    TArray<TSubclassOf<UItemType>> ContainerSubtypeWhitelist;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    // Can be generally left unspecified 
    FLinearColor MaterialColor;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TerrainCollectionMultiplier;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* TerrainCollectionMesh;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* TerrainVolumeMesh;
    
    UPROPERTY(SimpleDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    // The Actor (PhysicalItem) that this ItemType represents
    TSubclassOf<AActor> PickupActor;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemType> DefaultContainerType;
    
    UPROPERTY(SimpleDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    // Bundle --> Individual
    TSubclassOf<UItemType> UnbundleType;
    
    UPROPERTY(SimpleDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    // Individual --> Bundle
    TSubclassOf<UItemType> BundleType;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemType> DefaultContainerIndicatorType;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAstroGameMenuTutoriaSlideCardKey AstropediaResourceType;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString LTEName;
    
protected:
    UPROPERTY(SimpleDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    // Item recipe
    FRecipe ConstructionRecipe;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMegastructureRecipe* MegastructureRecipe;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHasAltConstructionRecipe;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRecipe AltConstructionRecipe;
    
public:
    UPROPERTY(SimpleDisplay, BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    // Research catalog data
    UItemCatalogData* CatalogData;
    
    UPROPERTY(SimpleDisplay, BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    // Research subject definition, if this item can be placed into a Research Chamber
    UResearchSubjectDefinition* ResearchSubjectDefinition;
    
    UPROPERTY(SimpleDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    // CrateOverlayTexture
    UTexture* CrateOverlayTexture;
    
    UPROPERTY(SimpleDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    // WidgetIcon
    UTexture2D* WidgetIcon;
    
    UItemType();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    UMegastructureRecipe* GetMegastructureRecipe() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FRecipe GetConstructionRecipe() const;
    
};

