#include "AutoCraneManager.h"

class AAutoCrane;
class ASolarBody;

void UAutoCraneManager::OnTransferItemSet(AAutoCrane* Crane) {
}

void UAutoCraneManager::OnTransferItemReleased(AAutoCrane* Crane) {
}

void UAutoCraneManager::OnTransferItemFullyEmplaced(AAutoCrane* Crane) {
}

void UAutoCraneManager::OnTransferItemDestroyed(AAutoCrane* Crane) {
}

void UAutoCraneManager::OnLocalSolarBodyChanged(ASolarBody* newBody) {
}

void UAutoCraneManager::OnCraneReleasedFromSlot(AAutoCrane* Crane) {
}

void UAutoCraneManager::OnCranePowerChanged(AAutoCrane* Crane) {
}

void UAutoCraneManager::OnCranePlacedInSlot(AAutoCrane* Crane) {
}

void UAutoCraneManager::OnCraneInputUse(AAutoCrane* Crane) {
}

void UAutoCraneManager::OnClientTransferProgressChanged(AAutoCrane* Crane) {
}

void UAutoCraneManager::OnClientCraneStateChanged(AAutoCrane* Crane) {
}

UAutoCraneManager::UAutoCraneManager() {
    this->PlayControllerCache = NULL;
    this->AstroCharacterCache = NULL;
}

