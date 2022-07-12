#pragma once
#include "CoreMinimal.h"
#include "AstroDatum.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
#include "AstroDatumRef.h"
#include "AstroDatumContainer.generated.h"

UCLASS(Abstract, Blueprintable)
class ASTRO_API UAstroDatumContainer : public UObject {
    GENERATED_BODY()
public:
    UAstroDatumContainer();
    UFUNCTION(BlueprintPure)
    static FAstroDatumRef MakeDatumRef_DO_NOT_USE_FROM_CPP(const FAstroDatum& Datum);
    
    UFUNCTION(BlueprintPure)
    static bool IsDatumRefValid_DO_NOT_USE_FROM_CPP(FAstroDatumRef DatumRef);
    
};

