#pragma once
#include "CoreMinimal.h"
#include "ResourceInfo.h"
#include "ResourceInfoNeeded.generated.h"

class UPrimitiveComponent;

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API AResourceInfoNeeded : public AResourceInfo
{
    GENERATED_BODY()
public:
    UPROPERTY(Export)
    UPrimitiveComponent *PlaceholderMesh;

    AResourceInfoNeeded();
};
