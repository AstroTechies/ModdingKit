#pragma once
#include "CoreMinimal.h"
#include "StormSpawnedLocalPointClientComponentState.h"
#include "StormSpawnedLocalPointClientComponentContainer.generated.h"

USTRUCT(BlueprintType)
struct FStormSpawnedLocalPointClientComponentContainer {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FStormSpawnedLocalPointClientComponentState> ClientComponentStates;
    
    ASTRO_API FStormSpawnedLocalPointClientComponentContainer();
};

