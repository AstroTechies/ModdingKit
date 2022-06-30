#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AstroDatumRef.h"
#include "AstroDatum.h"
#include "AstroDatumContainer.generated.h"

UCLASS(Blueprintable, Abstract, BlueprintType)
class ASTRO_API UAstroDatumContainer : public UObject
{
    GENERATED_BODY()
public:
    UAstroDatumContainer();
    UFUNCTION(BlueprintPure)
    static FAstroDatumRef MakeDatumRef_DO_NOT_USE_FROM_CPP(const FAstroDatum &Datum);

    UFUNCTION(BlueprintPure)
    static bool IsDatumRefValid_DO_NOT_USE_FROM_CPP(FAstroDatumRef DatumRef);
};
