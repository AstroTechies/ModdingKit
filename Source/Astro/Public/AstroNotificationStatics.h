#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
// CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=BlueprintFunctionLibrary -FallbackName=BlueprintFunctionLibrary
#include "AstroNotificationUnlockAuthoringData.h"
#include "AstroNotificationTagAuthoringData.h"
#include "AstroNotificationToastAuthoringData.h"
#include "AstroNotificationStatics.generated.h"

class AActor;
class USceneComponent;
class UAstroNotificationDatabase;
class UObject;
class UItemType;

UCLASS(Blueprintable)
class ASTRO_API UAstroNotificationStatics : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()
public:
    UAstroNotificationStatics();
    UFUNCTION(meta = (WorldContext = "WorldContextObject"))
    static void PresentUnlockNotification(UObject *WorldContextObject, const FAstroNotificationUnlockAuthoringData &AuthoringData);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"))
    static void PresentToastNotification(UObject *WorldContextObject, const FAstroNotificationToastAuthoringData &AuthoringData, bool bPushToFrontOfQueue);

    UFUNCTION()
    static void PresentResearchPointGrantNotificationData(AActor *OwningActor, int32 ResearchPoints);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"))
    static void PresentCatalogItemUnlockNotification(UObject *WorldContextObject, TSubclassOf<UItemType> ItemType);

    UFUNCTION(BlueprintCallable)
    static void ImmediatelyPresentNotificationWidget(AActor *OwningActor, const FAstroNotificationTagAuthoringData &AuthoringData, USceneComponent *OverrideAnchorReference);

    UFUNCTION(BlueprintPure)
    static UAstroNotificationDatabase *GetAstroNotificationDatabase();

    UFUNCTION(BlueprintCallable)
    static void EnqueueNotificationWidget(AActor *OwningActor, const FAstroNotificationTagAuthoringData &AuthoringData, USceneComponent *OverrideAnchorReference, bool AllowDuplicateEnqueue);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintCallable)
    static FAstroNotificationTagAuthoringData CreateNotificationTagDataForItemPing(UObject *WorldContextObject, TSubclassOf<UItemType> ItemType);
};
