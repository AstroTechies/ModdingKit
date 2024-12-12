#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "StormSpawnedLocalPointFXData.generated.h"

class UParticleSystemComponent;

USTRUCT(BlueprintType)
struct FStormSpawnedLocalPointFXData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UParticleSystemComponent* ParticleSystemComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Location;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Radius;
    
    ASTRO_API FStormSpawnedLocalPointFXData();
};

