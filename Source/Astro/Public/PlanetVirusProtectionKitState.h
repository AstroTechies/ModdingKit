#pragma once
#include "CoreMinimal.h"
#include "VirusProtectionKitState.h"
#include "PlanetVirusProtectionKitState.generated.h"

USTRUCT(BlueprintType)
struct FPlanetVirusProtectionKitState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FVirusProtectionKitState> StormIDToVirusProtectionStateTable;
    
    ASTRO_API FPlanetVirusProtectionKitState();
};

