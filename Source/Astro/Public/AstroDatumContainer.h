#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AstroDatum.h"
#include "AstroDatumRef.h"
#include "AstroDatumContainer.generated.h"

UCLASS(Abstract, Blueprintable)
class ASTRO_API UAstroDatumContainer : public UObject {
    GENERATED_BODY()
public:
    UAstroDatumContainer();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FAstroDatumRef MakeDatumRef_DO_NOT_USE_FROM_CPP(const FAstroDatum& Datum);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsDatumRefValid_DO_NOT_USE_FROM_CPP(FAstroDatumRef DatumRef);
    
};

