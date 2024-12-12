#pragma once
#include "CoreMinimal.h"
#include "ResourceInfo.h"
#include "ResourceInfoNeeded.generated.h"

class UPrimitiveComponent;

UCLASS(Blueprintable)
class ASTRO_API AResourceInfoNeeded : public AResourceInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPrimitiveComponent* PlaceholderMesh;
    
    AResourceInfoNeeded(const FObjectInitializer& ObjectInitializer);

};

