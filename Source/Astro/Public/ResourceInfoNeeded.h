#pragma once
#include "CoreMinimal.h"
#include "ResourceInfo.h"
#include "ResourceInfoNeeded.generated.h"

class UPrimitiveComponent;

UCLASS(Blueprintable)
class ASTRO_API AResourceInfoNeeded : public AResourceInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UPrimitiveComponent* PlaceholderMesh;
    
    AResourceInfoNeeded();
};

