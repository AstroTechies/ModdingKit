#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
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

