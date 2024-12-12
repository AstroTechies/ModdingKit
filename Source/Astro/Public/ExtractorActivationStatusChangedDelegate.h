#pragma once
#include "CoreMinimal.h"
#include "EResourceExtractorActivationFlags.h"
#include "ExtractorActivationStatusChangedDelegate.generated.h"

class AResourceExtractor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FExtractorActivationStatusChanged, AResourceExtractor*, Extractor, EResourceExtractorActivationFlags, ChangedFlag, bool, IsActive);

