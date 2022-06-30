#pragma once
#include "CoreMinimal.h"
#include "AstroEntityTaskManager.h"
#include "AstroStreamingPowerTickTaskManager.generated.h"

class UStreamingPowerSystem;

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API UAstroStreamingPowerTickTaskManager : public UAstroEntityTaskManager
{
    GENERATED_BODY()
public:
    UPROPERTY(Transient)
    UStreamingPowerSystem *StreamingPowerSystem;

    UAstroStreamingPowerTickTaskManager();
};
