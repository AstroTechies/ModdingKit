#pragma once
#include "CoreMinimal.h"
#include "ItemSlot.h"
#include "ControlSlot.generated.h"

UCLASS(Abstract, Blueprintable)
class ASTRO_API AControlSlot : public AItemSlot {
    GENERATED_BODY()
public:
    AControlSlot(const FObjectInitializer& ObjectInitializer);

};

