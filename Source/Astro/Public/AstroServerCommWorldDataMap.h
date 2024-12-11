#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AstroServerCommWorldData.h"
#include "AstroServerCommWorldDataMap.generated.h"

UCLASS(Blueprintable)
class ASTRO_API UAstroServerCommWorldDataMap : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<uint64, FAstroServerCommWorldData> Map;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FAstroServerCommWorldData CustomGameManagerServerComm;
    
    UAstroServerCommWorldDataMap();

};

