#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
#include "AstroServerCommWorldData.h"
#include "AstroServerCommWorldDataMap.generated.h"

UCLASS(Blueprintable)
class ASTRO_API UAstroServerCommWorldDataMap : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<uint64, FAstroServerCommWorldData> Map;
    
    UAstroServerCommWorldDataMap();
};

