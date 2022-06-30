#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "UObject/Object.h"
#include "SimpleFocusTooltipWidgetAuthoringData.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "AstroGameSingleton.generated.h"

class UMaterialInstance;
class UAstroGameMenuWidget;
class UEmoteTable;
class UAstroGameMenuTutorialSlideDeckDatabase;
class UMessageOfTheDay;
class UAstroGameMenuPopoutWidget;
class UUserWidget;
class UGameplayGlobals;
class URewardTable;
class UAstroCharacterCustomizationGlobals;
class UItemList;
class UResearchProgressionTable;
class APlanetProxyActor;
class USuitTable;
class UDeployableItemPackageCatalog;
class UAstroUIAudioDatabase;
class UDestructionDefinitionTable;
class UItemType;
class APhysicalItem;
class UScrapConversionTable;
class USoilConversionTable;
class UItemTradeValueTable;
class AResourceInfo;
class UCraftingDependencyMapList;
class ULocalizationCultureOptions;
class UStaticMesh;
class UInputKeyToIconMapping;
class UAstroDiscreteInputDefinitionDatabase;
class UTetherSystemProperties;
class UTexture2D;
class UAstroFoliageDestructionData;
class UAstroPopupBadgeDatabase;
class UFont;
class UAstroUIStylingDatabase;
class ARailNetwork;
class UAstroPlatformSpecificCustomizationContent;
class AActor;
class AResourceInfoNeeded;
class APlacingActuatorConnection;
class UAchievementDefinitionTable;
class UControlSymbol;
class UMaterialInterface;
class UAstroEntityWorldConfig;
class UAstroColorDatabase;
class UAstroTooltipWidget;
class UAstroNotificationDatabase;
class UStringTable;
class UVoxelVolumePaintModePalette;
class UAstroGameSingleton;

UCLASS(Blueprintable, Abstract, BlueprintType)
class ASTRO_API UAstroGameSingleton : public UObject
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    uint8 bIsExperimentalBuild : 1;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TSubclassOf<UAstroGameMenuWidget> GameMenu;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    UAstroGameMenuTutorialSlideDeckDatabase *TutorialSlideDeckDatabase;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TSubclassOf<UAstroGameMenuPopoutWidget> DefaultPopoutWrapper;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TSubclassOf<UUserWidget> HelpMenu;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TSubclassOf<UUserWidget> HelpMenuGamepad;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TSubclassOf<UUserWidget> DebugMenu;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    UGameplayGlobals *GameplayGlobals;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TSubclassOf<UItemList> MasterItemList;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TSubclassOf<UItemList> ForcedPackageIncludes;

    UPROPERTY(EditAnywhere)
    UResearchProgressionTable *ResearchProgressionTable;

    UPROPERTY(EditAnywhere)
    UDeployableItemPackageCatalog *DeployableItemPackageCatalog;

    UPROPERTY(EditAnywhere)
    UDestructionDefinitionTable *DestructionDefinitionTable;

    UPROPERTY(EditAnywhere)
    TSubclassOf<UItemType> ScrapItemType;

    UPROPERTY(EditAnywhere)
    TSubclassOf<UItemType> SedimentItemType;

    UPROPERTY(EditAnywhere)
    TSubclassOf<APhysicalItem> NuggetBaseClass;

    UPROPERTY(EditAnywhere)
    UScrapConversionTable *ScrapConversionTable;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    USoilConversionTable *SoilConversionTable;

    UPROPERTY(EditAnywhere)
    UItemTradeValueTable *ItemTradeValueTable;

    UPROPERTY(EditAnywhere)
    UCraftingDependencyMapList *CraftingSources;

    UPROPERTY(EditAnywhere)
    UInputKeyToIconMapping *InputKeyToIconMapping;

    UPROPERTY(EditAnywhere)
    UAstroDiscreteInputDefinitionDatabase *DiscreteAstroInputDefinitionDatabase;

    UPROPERTY(EditAnywhere)
    UTetherSystemProperties *TetherProperties;

    UPROPERTY(EditAnywhere)
    UAstroFoliageDestructionData *FoliageDestructionData;

    UPROPERTY(EditDefaultsOnly)
    float WindPowerActivationThreshold;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    float DefaultHoldInputDuration;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    float DefaultHoldInputCancelTreshold;

    UPROPERTY(EditDefaultsOnly)
    TSubclassOf<ARailNetwork> RailNetworkType;

public:
    UPROPERTY(EditDefaultsOnly)
    FText IndicatorRequestItemOverrideSubtitle;

    UPROPERTY(EditDefaultsOnly)
    FText IndicatorOutputItemOverrideSubtitle;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TSubclassOf<APlanetProxyActor> PlanetProxyActor;

    UPROPERTY(EditAnywhere)
    TSubclassOf<AActor> WindstormClass;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TSubclassOf<URewardTable> RewardTable;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TSubclassOf<AActor> ControlSymbolIconActor;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TSubclassOf<AActor> ControlSymbolIconPingActor;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TSubclassOf<AResourceInfo> ResourceInfoActor;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TSubclassOf<AResourceInfoNeeded> ResourceInfoNeededActor;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TSubclassOf<AActor> ResourceInfoPingActor;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TSubclassOf<AActor> PowerPingActorCharge;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TSubclassOf<AActor> PowerPingActorDischarge;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TSubclassOf<UControlSymbol> ConnectSymbol;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TSubclassOf<UControlSymbol> PullConnectionSymbol;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TSubclassOf<UControlSymbol> LiftItemSymbol;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TSubclassOf<UControlSymbol> PlaceItemSymbol;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TArray<FString> GlobalSoundBanks;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FString PowerDeltaAddAudioEvent;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FString PowerDeltaSubtractAudioEvent;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FString CannotQuickStowItemAudioEvent;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    UMaterialInterface *IndicatorMaterial;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    UMaterialInterface *InvalidIndicatorMaterial;

    UPROPERTY(EditAnywhere)
    UMaterialInterface *ButtonMaterial;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    UMaterialInterface *PrintingMaterial;

    UPROPERTY(EditAnywhere)
    UFont *ASTROFONT;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TArray<FLinearColor> DefaultPlayerAccentColors;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TArray<FText> DefaultPlayerAccentName;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    UMaterialInterface *PowerColdMaterial;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    UMaterialInterface *PowerHotMaterial;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TMap<FString, UMaterialInstance *> CrateLogoMaterialInstances;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    UAstroColorDatabase *AstroColorDatabase;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    UAstroUIStylingDatabase *AstroUIStylingDatabase;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    UAstroUIAudioDatabase *AstroUIAudioDatabase;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    UMaterialInterface *NonFlashingButtonMaterial;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    UMaterialInterface *FlashingButtonMaterial;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    UStaticMesh *ResourceShellMesh;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    UStaticMesh *CylinderButtonOuterMesh;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    UStaticMesh *CylinderButtonInnerMesh;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    UStaticMesh *CylinderButtonFullMesh;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    UStaticMesh *BoxButtonOuterMesh;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    UStaticMesh *BoxButtonInnerMesh;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    UStaticMesh *BoxButtonFullMesh;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    ULocalizationCultureOptions *LocalizationCultureOptions;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FLinearColor ConfirmButtonColor;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FLinearColor CancelButtonColor;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    UTexture2D *FoliageLUT;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    UObject *ResourceObjectTooltipBadgeBackgroundSquare;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    UObject *ResourceObjectTooltipBadgeBackgroundRound;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FLinearColor DefaultTooltipBadgeColor;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FSimpleFocusTooltipWidgetAuthoringData SalvageDefaultTooltipData;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FSimpleFocusTooltipWidgetAuthoringData BundleableSalvageDefaultTooltipData;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TSubclassOf<UAstroTooltipWidget> ToolTipWidget;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    UAstroNotificationDatabase *AstroNotificationDatabase;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    UAstroPopupBadgeDatabase *AstroPopupBadgeDatabase;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    UStringTable *AstroErrorStringTable;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TSubclassOf<UUserWidget> InteractionIndicatorPip;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FVector2D DefaultUIPivot;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    UMessageOfTheDay *DefaultMessageOfTheDay;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    UMessageOfTheDay *RequireNintendoLinkAccountMessageOfTheDay;

    UPROPERTY(AdvancedDisplay, EditAnywhere)
    UAstroEntityWorldConfig *EntityWorldConfig;

    UPROPERTY(EditDefaultsOnly)
    UAchievementDefinitionTable *AchievementDefinitions;

    UPROPERTY(EditAnywhere)
    UVoxelVolumePaintModePalette *CreativeModePaintPalette;

    UPROPERTY(EditAnywhere)
    uint32 CreativeModePaintSpecialPaletteIndex;

    UPROPERTY(EditAnywhere)
    TArray<TSubclassOf<UItemType>> AutoCraneItemBlackList;

    UPROPERTY(EditAnywhere)
    TArray<TSubclassOf<UItemType>> ResourceExtractorWhiteList;

    UPROPERTY(EditAnywhere)
    TSubclassOf<APlacingActuatorConnection> ActuatorConnection;

    UPROPERTY(EditAnywhere)
    TSubclassOf<AActor> CurrentLTERocket;

    UAstroGameSingleton();
    UFUNCTION(BlueprintPure)
    static UAstroGameSingleton *GetAstroGameSingleton();
};
