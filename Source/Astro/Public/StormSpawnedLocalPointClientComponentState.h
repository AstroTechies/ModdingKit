#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "StormSpawnedLocalPointClientComponentState.generated.h"

class UParticleSystemComponent;

USTRUCT(BlueprintType)
struct FStormSpawnedLocalPointClientComponentState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UParticleSystemComponent* ParticleSystemComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Location;
    
    ASTRO_API FStormSpawnedLocalPointClientComponentState();
};

