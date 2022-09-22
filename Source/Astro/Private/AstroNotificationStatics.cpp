#include "AstroNotificationStatics.h"
#include "Templates/SubclassOf.h"

class UObject;
class AActor;
class UAstroNotificationDatabase;
class UItemType;
class USceneComponent;

void UAstroNotificationStatics::PresentUnlockNotification(UObject* WorldContextObject, const FAstroNotificationUnlockAuthoringData& AuthoringData) {
}

void UAstroNotificationStatics::PresentToastNotification(UObject* WorldContextObject, const FAstroNotificationToastAuthoringData& AuthoringData, bool bPushToFrontOfQueue) {
}

void UAstroNotificationStatics::PresentResearchPointGrantNotificationData(AActor* OwningActor, int32 ResearchPoints) {
}

void UAstroNotificationStatics::PresentCatalogItemUnlockNotification(UObject* WorldContextObject, TSubclassOf<UItemType> ItemType) {
}

void UAstroNotificationStatics::ImmediatelyPresentNotificationWidget(AActor* OwningActor, const FAstroNotificationTagAuthoringData& AuthoringData, USceneComponent* OverrideAnchorReference) {
}

UAstroNotificationDatabase* UAstroNotificationStatics::GetAstroNotificationDatabase() {
    return NULL;
}

void UAstroNotificationStatics::EnqueueNotificationWidget(AActor* OwningActor, const FAstroNotificationTagAuthoringData& AuthoringData, USceneComponent* OverrideAnchorReference, bool AllowDuplicateEnqueue) {
}

FAstroNotificationTagAuthoringData UAstroNotificationStatics::CreateNotificationTagDataForItemPing(UObject* WorldContextObject, TSubclassOf<UItemType> ItemType) {
    return FAstroNotificationTagAuthoringData{};
}

UAstroNotificationStatics::UAstroNotificationStatics() {
}

