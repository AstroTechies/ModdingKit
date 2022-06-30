#include "ResourceExtractorManager.h"

class AResourceExtractor;

void UResourceExtractorManager::OnHammerDroppped(AResourceExtractor* Extractor) {
}

void UResourceExtractorManager::OnClientVisualStateChanged(AResourceExtractor* Extractor) {
}

void UResourceExtractorManager::OnClientAnimProgressChanged(AResourceExtractor* Extractor) {
}

void UResourceExtractorManager::OnBillowsBegin(AResourceExtractor* Extractor) {
}

void UResourceExtractorManager::OnActivationStatusChanged(AResourceExtractor* Extractor, EResourceExtractorActivationFlags ChangedFlag, bool IsActive) {
}

UResourceExtractorManager::UResourceExtractorManager() {
    this->GroupIDCounter = 0;
}

