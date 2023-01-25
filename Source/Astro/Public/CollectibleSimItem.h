#pragma once
#include "CoreMinimal.h"
#include "CollectibleSimItem.generated.h"

class UStaticMeshComponent;

USTRUCT(BlueprintType)
struct FCollectibleSimItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* Mesh;
    
    ASTRO_API FCollectibleSimItem();
};

