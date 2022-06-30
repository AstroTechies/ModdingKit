#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AstroEntitySystem.generated.h"

class UAstroEntityWorld;

UCLASS(Blueprintable, Abstract)
class ASTRO_API UAstroEntitySystem : public UObject
{
    GENERATED_BODY()
public:
protected:
    UPROPERTY(Transient)
    UAstroEntityWorld *CachedEntityWorld;

public:
    UAstroEntitySystem();
};
