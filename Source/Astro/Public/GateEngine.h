#pragma once
#include "CoreMinimal.h"
#include "GateObject.h"
#include "GateEngine.generated.h"

UCLASS(Blueprintable)
class ASTRO_API AGateEngine : public AGateObject {
    GENERATED_BODY()
public:
    AGateEngine(const FObjectInitializer& ObjectInitializer);

};

