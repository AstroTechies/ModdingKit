#include "CapturableSnail.h"
#include "PlanetEffect.h"

class APhysicalItem;
class AActor;
class APlayController;

void ACapturableSnail::SetOwningCaptureTerrarium(APhysicalItem* captureTerrarium) {
}






void ACapturableSnail::OnEffectRelevanceChanged(bool IsInRelevancy) {
}


void ACapturableSnail::OnActorOnscreenChanged(AActor* Actor, bool bIsOnscreen, APlayController* Player) {
}

void ACapturableSnail::MULTI_OnEmoteWheelOpenedOrClosed_Implementation(bool bWheelOpen, APlayController* Player) {
}
bool ACapturableSnail::MULTI_OnEmoteWheelOpenedOrClosed_Validate(bool bWheelOpen, APlayController* Player) {
    return true;
}

void ACapturableSnail::AuthorityStartCheckOnscreen() {
}

void ACapturableSnail::AuthorityClearCheckOnscreen() {
}

ACapturableSnail::ACapturableSnail() {
    this->PlanetEffect = CreateDefaultSubobject<UPlanetEffect>(TEXT("Planet Effect"));
    this->SightDist = 2500.00f;
    this->FaceTargetSpeed = 360.00f;
    this->OwningCaptureTerrarium = NULL;
    this->CurrSightTarget = NULL;
}

