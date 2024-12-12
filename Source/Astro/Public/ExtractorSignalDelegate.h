#pragma once
#include "CoreMinimal.h"
#include "ExtractorSignalDelegate.generated.h"

class AResourceExtractor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FExtractorSignal, AResourceExtractor*, Extractor);

