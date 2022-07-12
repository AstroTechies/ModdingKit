#include "AstroNotificationStatics.h"
#include "Templates/SubclassOf.h"

class UAstroNotificationDatabase;
class USceneComponent;
class UObject;
class UItemType;
class AActor;

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

