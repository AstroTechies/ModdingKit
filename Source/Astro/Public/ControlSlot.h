#pragma once
#include "CoreMinimal.h"
#include "ItemSlot.h"
#include "ControlSlot.generated.h"

UCLASS(Blueprintable, Abstract)
class ASTRO_API AControlSlot : public AItemSlot
{
    GENERATED_BODY()
public:
    AControlSlot();
};
