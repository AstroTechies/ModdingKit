#pragma once
#include "CoreMinimal.h"
#include "AstroEntityTaskManager.h"
#include "AstroStreamingPowerTickTaskManager.generated.h"

class UStreamingPowerSystem;

UCLASS(Blueprintable)
class ASTRO_API UAstroStreamingPowerTickTaskManager : public UAstroEntityTaskManager {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UStreamingPowerSystem* StreamingPowerSystem;
    
    UAstroStreamingPowerTickTaskManager();

};

