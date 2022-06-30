#pragma once
#include "CoreMinimal.h"
#include "ItemSlot.h"
#include "ResourceSlot.generated.h"

UCLASS(Blueprintable, Abstract)
class ASTRO_API AResourceSlot : public AItemSlot
{
    GENERATED_BODY()
public:
    AResourceSlot();
};
