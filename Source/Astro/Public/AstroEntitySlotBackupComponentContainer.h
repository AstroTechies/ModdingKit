#pragma once
#include "CoreMinimal.h"
#include "AstroEntityComponentContainer.h"
#include "AstroEntitySlotBackupComponentContainer.generated.h"

UCLASS(Blueprintable)
class ASTRO_API UAstroEntitySlotBackupComponentContainer : public UAstroEntityComponentContainer {
    GENERATED_BODY()
public:
    UAstroEntitySlotBackupComponentContainer();
};

