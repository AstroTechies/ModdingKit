#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "Engine/DataAsset.h"
#include "UObject/NoExportTypes.h"
#include "EAstroColor.h"
#include "AstroNotificationTagAuthoringData.h"
#include "AstroNotificationUnlockAuthoringData.h"
#include "AstroNotificationDatabase.generated.h"

class UTexture2D;
class UAstroNotificationUnlockWidget;
class UAstroNotificationTagWidget;
class UTexture;
class UAstroNotificationToastWidget;

UCLASS(Blueprintable, BlueprintType)
class UAstroNotificationDatabase : public UDataAsset
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FLinearColor DefaultNotificationBadgeColor;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FLinearColor DefaultNotificationBadgeStrokeColor;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    float TagNotificationQueueDisplayFrequency;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    float UnlockNotificationQueueDisplayFrequency;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    float ToastNotificationQueueDisplayFrequency;

    UPROPERTY(EditDefaultsOnly)
    FText ResearchBytesGainedPrefixText;

    UPROPERTY(EditDefaultsOnly)
    FText ResearchBytesLostTextPrefixText;

    UPROPERTY(EditDefaultsOnly)
    FText ResearchCatalogItemUnlockedPrefixText;

    UPROPERTY(EditDefaultsOnly)
    FText CosmeticItemUnlockedPrefixText;

    UPROPERTY(EditDefaultsOnly)
    FText MissionActivatedTitleText;

    UPROPERTY(EditDefaultsOnly)
    FText MissionCompletedTitleText;

    UPROPERTY(EditDefaultsOnly)
    FText MissionUpdatedPrefixText;

    UPROPERTY(EditDefaultsOnly)
    FString UnlockedResearchCatalogItemNotificationAudioEvent;

    UPROPERTY(EditDefaultsOnly)
    FString UnlockedCosmeticNotificationAudioEvent;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    EAstroColor SuitUnlockNotifIconColor;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    UTexture2D *SuitUnlockNotifIcon;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FText SuitUnlockSubtitle;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    EAstroColor EmoteUnlockNotifIconColor;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    UTexture2D *EmoteUnlockNotifIcon;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FText EmoteUnlockSubtitle;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    EAstroColor VisorUnlockNotifIconColor;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    UTexture2D *VisorUnlockNotifIcon;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    EAstroColor BundleUnlockNotifIconColor;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    UTexture2D *BundleUnlockNotifIcon;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FText BundleUnlockSubtitle;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    UTexture2D *MissionObjectiveProgressNotifIcon;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FText VisorUnlockSubtitle;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    EAstroColor PaletteUnlockNotifIconColor;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    UTexture2D *PaletteUnlockNotifIcon;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FText PaletteUnlockSubtitle;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    EAstroColor HatUnlockNotifIconColor;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    UTexture2D *HatUnlockNotifIcon;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FText HatUnlockSubtitle;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    EAstroColor MaskUnlockNotifIconColor;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    UTexture2D *MaskUnlockNotifIcon;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FText MaskUnlockSubtitle;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    EAstroColor PhotoFilterUnlockNotifIconColor;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    UTexture2D *PhotoFilterUnlockNotifIcon;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FText PhotoFilterUnlockSubtitle;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FText CarePackageTitle;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FText CarePackageSubtitle;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    UTexture *CarePackageIcon;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TSubclassOf<UAstroNotificationTagWidget> AstroNotificationTagWidgetClass;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TSubclassOf<UAstroNotificationUnlockWidget> AstroNotificationUnlockWidgetClass;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TSubclassOf<UAstroNotificationToastWidget> AstroNotificationToastWidgetClass;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    FAstroNotificationTagAuthoringData NotificationOxygenSuffocating;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    FAstroNotificationTagAuthoringData NotificationAstroNoPower;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    FAstroNotificationTagAuthoringData NotificationAstroBackpackFull;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    FAstroNotificationTagAuthoringData NotificationShuttleNoFuel;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    FAstroNotificationTagAuthoringData NotificationShuttleNoThruster;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    FAstroNotificationTagAuthoringData NotificationShuttleSkyObstructed;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    FAstroNotificationTagAuthoringData NotificationVTOLNoLandingZone;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    FAstroNotificationTagAuthoringData NotificationVTOLLandingZoneTooFar;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    FAstroNotificationTagAuthoringData NotificationResearchPointsGranted;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    FAstroNotificationTagAuthoringData NotificationDurableItemUnlocked;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    FAstroNotificationUnlockAuthoringData NotificationSaveFailedMaxSaveSizeFileExceeded;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    FAstroNotificationUnlockAuthoringData NotificationSaveFailedInsufficientStorageSpace;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    FAstroNotificationUnlockAuthoringData NotificationSaveFailedUnknownError;

    UAstroNotificationDatabase();
};
