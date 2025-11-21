#pragma once
#include "CoreMinimal.h"
#include "EActuatorChannel.h"
#include "ActuatorCableRef.generated.h"

USTRUCT(BlueprintType)
struct FActuatorCableRef {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 CableIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 bInUse: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    EActuatorChannel ActuatorChannel;
    
    ASTRO_API FActuatorCableRef();
};

