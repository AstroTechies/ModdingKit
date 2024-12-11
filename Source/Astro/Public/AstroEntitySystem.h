#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AstroEntitySystem.generated.h"

class UAstroEntityWorld;

UCLASS(Abstract, Blueprintable)
class ASTRO_API UAstroEntitySystem : public UObject {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAstroEntityWorld* CachedEntityWorld;
    
public:
    UAstroEntitySystem();

};

