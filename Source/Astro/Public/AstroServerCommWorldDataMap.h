#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AstroServerCommWorldData.h"
#include "AstroServerCommWorldDataMap.generated.h"

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API UAstroServerCommWorldDataMap : public UObject
{
    GENERATED_BODY()
public:
    UPROPERTY(Transient)
    TMap<uint64, FAstroServerCommWorldData> Map;

    UAstroServerCommWorldDataMap();
};
