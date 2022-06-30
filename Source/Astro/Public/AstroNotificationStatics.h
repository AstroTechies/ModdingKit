#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "AstroNotificationTagAuthoringData.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AstroNotificationUnlockAuthoringData.h"
#include "AstroNotificationToastAuthoringData.h"
#include "AstroNotificationStatics.generated.h"

class AActor;
class UObject;
class UItemType;
class USceneComponent;
class UAstroNotificationDatabase;

UCLASS(Blueprintable, BlueprintType)
class ASTRO_API UAstroNotificationStatics : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()
public:
    UAstroNotificationStatics();
    UFUNCTION()
    static void PresentUnlockNotification(UObject *WorldContextObject, const FAstroNotificationUnlockAuthoringData &AuthoringData);

    UFUNCTION()
    static void PresentToastNotification(UObject *WorldContextObject, const FAstroNotificationToastAuthoringData &AuthoringData, bool bPushToFrontOfQueue);

    UFUNCTION()
    static void PresentResearchPointGrantNotificationData(AActor *OwningActor, int32 ResearchPoints);

    UFUNCTION()
    static void PresentCatalogItemUnlockNotification(UObject *WorldContextObject, TSubclassOf<UItemType> ItemType);

    UFUNCTION(BlueprintCallable)
    static void ImmediatelyPresentNotificationWidget(AActor *OwningActor, const FAstroNotificationTagAuthoringData &AuthoringData, USceneComponent *OverrideAnchorReference);

    UFUNCTION(BlueprintPure)
    static UAstroNotificationDatabase *GetAstroNotificationDatabase();

    UFUNCTION(BlueprintCallable)
    static void EnqueueNotificationWidget(AActor *OwningActor, const FAstroNotificationTagAuthoringData &AuthoringData, USceneComponent *OverrideAnchorReference, bool AllowDuplicateEnqueue);

    UFUNCTION(BlueprintCallable)
    static FAstroNotificationTagAuthoringData CreateNotificationTagDataForItemPing(UObject *WorldContextObject, TSubclassOf<UItemType> ItemType);
};
